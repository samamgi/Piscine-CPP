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

// int main(void)
// {
//     std::string input;
//     Zombie  *heap;

//     std::cout << "Put your stack (randomChump) Zombie name: ";
//     if (!getline(std::cin, input))
//     {
//         std::cout << std::endl;
//         return (1);
//     }
//     randomChump(input);
//     std::cout << "Put your heap (newZombie) Zombie name: ";
//     if (!getline(std::cin, input))
//     {
//         std::cout << std::endl;
//         return (1);
//     }
//     heap = newZombie(input);
//     heap->announce();
//     delete (heap);
//     return (0);
// }

int main(void)
{
    Zombie  *heap;

    heap = newZombie("heap");
    randomChump("stack");
    heap->announce();
    delete (heap);
    return (0);
}