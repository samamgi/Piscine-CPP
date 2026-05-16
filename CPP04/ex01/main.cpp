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

	std::cout << std::endl;
	const Animal* x = new Dog();
	const Animal* y = new Cat();
	
	delete x;//should not create a leak
	delete y;

	const	Dog* a = new Dog();
	const	Cat* b= new Cat();
	Dog	sourcedog;

	sourcedog.GetBrain()->PutIdea(0, "test copy");
	Dog copydog = sourcedog;
	std::cout << std::endl;
	copydog.GetBrain()->printidea(0);
	sourcedog.GetBrain()->printidea(0);
	std::cout << std::endl;

	sourcedog.GetBrain()->PutIdea(0, "test copy changed");
	copydog.GetBrain()->printidea(0);
	sourcedog.GetBrain()->printidea(0);
	std::cout << std::endl;

	a->GetBrain()->PutIdea(-1, "test");
	a->GetBrain()->printidea(0);
	std::cout << std::endl;

	b->GetBrain()->PutIdea(5, "idea 5");
	b->GetBrain()->PutIdea(6, "idea 6");
	b->GetBrain()->printidea(5);
	b->GetBrain()->PutIdea(100, "dsadsa");
	b->GetBrain()->printbrain();

	std::cout << std::endl;
	a->GetBrain()->PutIdea(5, "idea 5");
	a->GetBrain()->PutIdea(6, "idea 6");
	a->GetBrain()->printidea(5);
	a->GetBrain()->PutIdea(100, "dsadsa");
	a->GetBrain()->printbrain();
    // delete (specifiedwrongcat);
	delete a;
	delete b;
	
	return (0);
}
