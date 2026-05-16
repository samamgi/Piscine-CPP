/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 23:13:55 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/09/28 01:23:25 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string new_type) : type(new_type)
{
}

Weapon::~Weapon()
{
    std::cout << "Weapon Destructor called" << std::endl;
}

const std::string&    Weapon::getType()
{
    const std::string& ref = type;
    return (ref);
}

void    Weapon::setType(const std::string &value)
{
    type = value;
}
