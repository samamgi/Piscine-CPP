/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 05:33:17 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/01/22 05:33:22 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->sethitPoints(100);
	this->setenergyPoints(100);
	this->setattackDamage(30);
}
FragTrap::FragTrap(const std::string new_name) : ClapTrap(new_name)
{
	std::cout << "FragTrap New constructor called" << std::endl;
	this->sethitPoints(100);
	this->setenergyPoints(100);
	this->setattackDamage(30);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	int	energyPoints;

	std::string name;
	name = FragTrap::getName();
	energyPoints = FragTrap::getenergyPoints();
	if (FragTrap::gethitPoints() > 0 && energyPoints > 0)
	{
		energyPoints--;
		FragTrap::setenergyPoints(energyPoints);
		std::cout << name << " FragTrap attacks " << target << " causing " << ClapTrap::getattackDamage() << " points of damage!" << std::endl;
	}
	else if (FragTrap::gethitPoints() > 0)
		std::cout << name << " FragTrap has no more energy to attack " << target << std::endl;
	else
		std::cout << name << " FragTrap is dead" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::string name;

    name = this->getName();
    std::cout << "FragTrap " << name << " requests positive high-fives" << std::endl;
}