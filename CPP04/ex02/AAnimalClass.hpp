/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimalClass.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:28:11 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/01/23 00:28:12 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMALCLASS_HPP
# define AANIMALCLASS_HPP

# include <iomanip>
# include <iostream>

class AAnimal
{
  protected:
	std::string type;

  public:
	AAnimal();
	AAnimal(std::string const new_type);
	AAnimal(const AAnimal &copy);
	AAnimal &operator=(const AAnimal &copy);
	virtual ~AAnimal();

	const std::string &gettype() const;

	virtual void makeSound() const = 0;
};

#endif
