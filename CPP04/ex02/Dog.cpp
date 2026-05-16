/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:28:41 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/01/23 00:28:42 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DogClass.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << "Dog Constructor called" << std::endl;
	brain = new Brain;
}

Dog::Dog(const Dog &copy) : AAnimal(copy.type)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	brain = new Brain(*copy.brain);
}

Dog &Dog::operator=(const Dog &copy)
{
	this->type = copy.type;
	*this->brain = *copy.brain;
	return (*this);
}

Dog::~Dog()
{
	delete	brain;

	std::cout << "Dog Destructor Called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bark..." << std::endl;
}

Brain *Dog::GetBrain() const
{
	return (this->brain);
}