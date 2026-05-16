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
    public:
        Zombie(std::string input_name);
        void    announce(void);
        ~Zombie();
};

void    randomChump(std::string name);
Zombie  *newZombie(std::string name);

#endif
