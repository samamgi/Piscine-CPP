/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 10:27:50 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/09/27 10:27:51 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string name;
        int         index;
    public:
        Zombie();
        ~Zombie();
        void    set_name(std::string input_name, int i);
        void    announce(int index);
};

Zombie  *zombieHorde(int N, std::string name);

#endif
