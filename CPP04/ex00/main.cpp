/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:28:51 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/01/23 00:28:52 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CatClass.hpp"
#include "DogClass.hpp"
#include "WrongCatClass.hpp"

int	main(void)
{
	const Animal		*meta = new Animal();
	const Animal		*j = new Dog();
	const Animal		*i = new Cat();
	const WrongAnimal	*wrongcat = new WrongCat();
    // const WrongCat      *specifiedwrongcat = new WrongCat();

	std::cout << j->gettype() << " " << std::endl;
	std::cout << i->gettype() << " " << std::endl;
	std::cout << wrongcat->gettype() << " " << std::endl;
    // std::cout << specifiedwrongcat->gettype() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	wrongcat->makeSound();
    // specifiedwrongcat->makeSound();
	meta->makeSound();
	delete (meta);
	delete (j);
	delete (i);
	delete (wrongcat);
    // delete (specifiedwrongcat);
	return (0);
}
