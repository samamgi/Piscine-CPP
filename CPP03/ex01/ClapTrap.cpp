/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 01:01:37 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/10/04 01:01:38 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string new_name) : name(new_name), hitPoints(10),
	energyPoints(10), attackDamage(0)
{
	std::cout << "New constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	ClapTrap::name = copy.name;
	ClapTrap::hitPoints = copy.hitPoints;
	ClapTrap::energyPoints = copy.energyPoints;
	ClapTrap::attackDamage = copy.attackDamage;
}

ClapTrap &ClapTrap::operator=(ClapTrap &copy)
{
	ClapTrap::name = copy.getName();
	ClapTrap::hitPoints = copy.gethitPoints();
	ClapTrap::energyPoints = copy.getenergyPoints();
	ClapTrap::attackDamage = copy.getattackDamage();
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::setName(std::string new_name)
{
	this->name = new_name;
}
void ClapTrap::sethitPoints(int new_hitPoints)
{
	this->hitPoints = new_hitPoints;
}
void ClapTrap::setenergyPoints(int new_energyPoints)
{
	this->energyPoints = new_energyPoints;
}

void ClapTrap::setattackDamage(int new_attackDamage)
{
	this->attackDamage = new_attackDamage;
}

std::string ClapTrap::getName()
{
    return(ClapTrap::name);
}

int ClapTrap::gethitPoints()
{
	return (ClapTrap::hitPoints);
}
int ClapTrap::getenergyPoints()
{
	return (ClapTrap::energyPoints);
}

int ClapTrap::getattackDamage()
{
	return (ClapTrap::attackDamage);
}

void ClapTrap::attack(const std::string &target)
{
	if (ClapTrap::gethitPoints() > 0 && ClapTrap::getenergyPoints() > 0)
	{
		(ClapTrap::energyPoints)--;
		std::cout << ClapTrap::getName() << " attacks " << target << " causing " << ClapTrap::getattackDamage() << " points of damage!" << std::endl;
	}
	else if (ClapTrap::gethitPoints() > 0)
		std::cout << ClapTrap::getName() << " has no more energy to attack " << target << std::endl;
	else
		std::cout << ClapTrap::getName() << " is dead" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (((ClapTrap::gethitPoints()) - amount) < 0)
	{
		ClapTrap::hitPoints = 0;
		std::cout << ClapTrap::getName() << " has taken " << amount << " points of damage and now has 0 hitPoints" << std::endl;
	}
	else
	{
		(ClapTrap::hitPoints) -= amount;
		if (ClapTrap::gethitPoints() < 0)
			(ClapTrap::hitPoints) = 0;
		std::cout << ClapTrap::getName() << " has taken " << amount << " points of damage and now has " << ClapTrap::gethitPoints() << " hitPoints" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (ClapTrap::getenergyPoints() > 0 && ClapTrap::gethitPoints() > 0)
	{
		(ClapTrap::energyPoints)--;
		(ClapTrap::hitPoints) += amount;
		std::cout << ClapTrap::getName() << " is repairing hiself and gained " << amount << " hitPoints for 1 energyPoint and has now " << ClapTrap::getenergyPoints() << " energyPoints and " << ClapTrap::gethitPoints() << " hitPoints" << std::endl;
	}
	else if (ClapTrap::gethitPoints() > 0)
		std::cout << ClapTrap::getName() << " has no more energy to repair hiself" << std::endl;
	else
		std::cout << ClapTrap::getName() << " is dead" << std::endl;
}
