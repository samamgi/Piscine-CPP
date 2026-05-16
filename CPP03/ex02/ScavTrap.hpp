/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 03:53:27 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/01/22 03:53:29 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iomanip>
# include <iostream>

class ScavTrap : public ClapTrap
{
  public:
	ScavTrap();
	ScavTrap(std::string new_name);
	~ScavTrap();

	void attack(const std::string &target);
	void guardGate();
};

#endif
