/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:28:31 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/01/23 00:28:32 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CatClass.hpp"

Cat::Cat() : AAnimal("Cat")
{
	std::cout << "Cat Constructor called" << std::endl;
	brain = new Brain;
}

Cat::Cat(const Cat &copy) : AAnimal(copy.type)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	brain = new Brain(*copy.brain);
}

Cat &Cat::operator=(const Cat &copy)
{
	this->type = copy.type;
	*this->brain = *copy.brain;
	return (*this);
}

Cat::~Cat()
{
	delete	brain;

	std::cout << "Cat Destructor Called" << std::endl;
}

void Cat::makeSound()	const
{
	std::cout << "Meow..." << std::endl;
}

Brain*	Cat::GetBrain()	const
{
	return(this->brain);
}
