/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 23:17:41 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/09/27 23:17:42 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon  *weapon;
    public:
        HumanB(std::string new_name);
        ~HumanB();
        void    setWeapon(Weapon& new_weapon);
        void    attack();
};
#endif
