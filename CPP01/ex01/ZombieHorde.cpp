/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:59:29 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/09/27 17:59:31 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name)
{
    Zombie  *horde;

    int i;

    i = 0;
    horde = new Zombie[N];
    while (i < N)
    {
        // if (i == 0)
        // {
        //     horde[0].set_name("le premier", 0);
        //     i++;
        // }
        // else
        // {
        //     horde[i].set_name(name, i);
        //     i++;
        // }
        horde[i].set_name(name, i);
        i++;
    }
    return (horde);
}
