/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:28:19 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/01/23 00:28:20 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AnimalClass.hpp"

Animal::Animal() : type("Default")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(std::string new_type) : type(new_type)
{
	std::cout << "Animal Type constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.type)
{
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
	this->type = copy.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

const std::string &Animal::gettype() const
{
	return (type);
}

void    Animal::makeSound() const
{
    std::cout << "Animal makes sound" << std::endl;
}
