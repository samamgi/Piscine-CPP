/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCatClass.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 00:28:27 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/01/23 00:28:28 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCATCLASS_HPP
# define WRONGCATCLASS_HPP

# include "WrongAnimalClass.hpp"
# include <iomanip>
# include <iostream>

class WrongCat : public WrongAnimal
{
  public:
	WrongCat();
	WrongCat(const WrongCat &copy);
	WrongCat &operator=(const WrongCat &copy);
	virtual ~WrongCat();

	void makeSound() const;
};

#endif
