/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 10:27:33 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/09/27 10:27:34 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("")
{
    std::cout << "Default constructor called" << std::endl;
}

void    Zombie::set_name(std::string input_name, int i)
{
    name = input_name;
    index = i;
}

void    Zombie::announce(int index)
{
    std::cout << name << " " << (index + 1) << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " " << (index + 1) << " has been destroyed" << std::endl;
}
