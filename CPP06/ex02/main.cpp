/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 20:01:38 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/12 19:04:35 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int	random;

	random = rand() % 3;
	if (random == 0)
		return (new A);
	else if (random == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Base ptr type is : A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Base ptr type is : B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Base ptr type is : C" << std::endl;
	else
		std::cout << "Base ptr type is invalid" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Base reference type is : A" << std::endl;
		return ;
	}
	catch (std::exception &)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Base reference type is : B" << std::endl;
		return ;
	}
	catch (std::exception &)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Base reference type is : C" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
    std::cout << "Base ref type is invalid" << std::endl;
	}
}

int	main(void)
{
  srand(time(NULL));
	try
	{
    Base	*valid = generate();
    Base &ref_valid = *valid;
		identify(valid);
		identify(ref_valid);
    if (valid != NULL)
      delete valid;
    std::cout << std::endl;
  }
  catch (std::exception &e)
  {
    return (EXIT_FAILURE);
  }
}
