/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 10:27:16 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/09/27 10:27:17 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdlib.h>

// int main(void)
// {
//     std::string input;
//     std::string n_input;
//     int         N;
//     int         i;
//     Zombie  *horde;

//     std::cout << "Put your Zombie name: ";
//     if (!getline(std::cin, input))
//     {
//         std::cout << std::endl;
//         return (1);
//     }
//       std::cout << "Put your Zombie number: ";
//     if (!getline(std::cin, n_input))
//     {
//         std::cout << std::endl;
//         return (1);
//     }
//     N = std::atoi((n_input.c_str()));
//     horde = zombieHorde(N, input);
//     i = 0;
//     while (i < N)
//     {
//         horde[i].announce(i);
//         i++;
//     }
//     delete[] (horde);
//     return (0);
// }

int main(void)
{
    std::string input;
    int         N;
    int         i;
    Zombie  *horde;

    N = 4;
    input = "Foo";
    horde = zombieHorde(N, input);
    i = 0;
    while (i < N)
    {
        horde[i].announce(i);
        i++;
    }
    delete[] (horde);
    return (0);
}