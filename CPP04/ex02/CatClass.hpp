/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CatClass.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:28:27 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/01/23 00:28:28 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CATCLASS_HPP
# define CATCLASS_HPP

# include "AAnimalClass.hpp"
# include "BrainClass.hpp"
# include <iomanip>
# include <iostream>

class Cat : public AAnimal
{
  private:
	Brain *brain;

  public:
	Cat();
	Cat(const Cat &copy);
	Cat &operator=(const Cat &copy);
	virtual ~Cat();

	virtual void makeSound() const;
	Brain *GetBrain() const;
};

#endif
