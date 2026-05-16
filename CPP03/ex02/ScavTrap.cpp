/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 03:53:31 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/01/22 04:10:21 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->sethitPoints(100);
	this->setenergyPoints(50);
	this->setattackDamage(20);
}

ScavTrap::ScavTrap(std::string new_name) : ClapTrap(new_name)
{
	std::cout << "ScavTrap New construcor called" << std::endl;
	this->sethitPoints(100);
	this->setenergyPoints(50);
	this->setattackDamage(20);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	int	energyPoints;
    std::string name;

    name = ScavTrap::getName();
	energyPoints = ScavTrap::getenergyPoints();
	if (ScavTrap::gethitPoints() > 0 && energyPoints > 0)
	{
		energyPoints--;
		ScavTrap::setenergyPoints(energyPoints);
		std::cout << name << " ScavTrap attacks " << target << " causing " << ClapTrap::getattackDamage() << " points of damage!" << std::endl;
	}
	else if (ScavTrap::gethitPoints() > 0)
		std::cout << name << " ScavTrap has no more energy to attack " << target << std::endl;
	else
		std::cout << name << " ScavTrap is dead" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << ScavTrap::getName() << " ScavTrap is now in Gate keeper mode." << std::endl;
}