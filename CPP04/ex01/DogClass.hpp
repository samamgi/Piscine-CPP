/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DogClass.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:28:35 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/01/23 00:28:37 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOGCLASS_HPP
# define DOGCLASS_HPP

# include "AnimalClass.hpp"
# include "BrainClass.hpp"
# include <iomanip>
# include <iostream>

class Dog : public Animal
{
  private:
	Brain *brain;

  public:
	Dog();
	Dog(const Dog &copy);
	Dog &operator=(const Dog &copy);
	virtual ~Dog();

	virtual void makeSound() const;
	Brain *GetBrain() const;
};

#endif
