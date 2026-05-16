/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AnimalClass.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:28:11 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/01/23 00:28:12 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMALCLASS_HPP
# define ANIMALCLASS_HPP

# include <iomanip>
# include <iostream>

class Animal
{
  protected:
	std::string type;

  public:
	Animal();
	Animal(std::string const new_type);
	Animal(const Animal &copy);
	Animal &operator=(const Animal &copy);
	virtual ~Animal();

	const std::string &gettype() const;

	virtual void makeSound() const;
};

#endif
