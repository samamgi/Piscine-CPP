/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 23:17:21 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/09/27 23:17:22 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string new_name, Weapon &new_weapon) : name(new_name), weapon(new_weapon)
{
}
void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA destructor called" << std::endl;
}