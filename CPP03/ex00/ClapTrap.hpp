/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 01:01:33 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/10/04 01:01:35 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iomanip>
# include <iostream>

class ClapTrap
{
  private:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;

  public:
	ClapTrap(); //check
	ClapTrap(std::string new_name); //check
	ClapTrap(const ClapTrap &copy); //check
	ClapTrap& operator=(ClapTrap &copy); //check
	~ClapTrap(); //check

    std::string   getName();
    int gethitPoints();
    int getenergyPoints();
    int getattackDamage();

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
