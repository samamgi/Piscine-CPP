/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 23:17:29 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/09/27 23:17:30 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string new_name) : name(new_name), weapon(NULL)
{
}
void HumanB::setWeapon(Weapon &new_weapon)
{
	weapon = &new_weapon;
}

void HumanB::attack()
{
	if (weapon != NULL)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " does not have weapon" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destructor called" << std::endl;
}
