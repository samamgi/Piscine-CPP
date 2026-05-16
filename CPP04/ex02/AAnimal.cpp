/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:28:19 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/01/23 00:28:20 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimalClass.hpp"

AAnimal::AAnimal() : type("Default")
{
	std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string new_type) : type(new_type)
{
	std::cout << "AAnimal Type constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) : type(copy.type)
{
	std::cout << "AAnimal Copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &copy)
{
	this->type = copy.type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor called" << std::endl;
}

const std::string &AAnimal::gettype() const
{
	return (type);
}