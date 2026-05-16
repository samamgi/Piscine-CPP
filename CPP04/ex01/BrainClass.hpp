/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrainClass.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 23:32:23 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/01/26 23:32:24 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAINCLASS_HPP
# define BRAINCLASS_HPP

# include <iomanip>
# include <iostream>

class Brain
{
  private:
	std::string ideas[100];

  public:
	Brain();
	Brain(const Brain &copy);
	Brain &operator=(const Brain &copy);
	virtual ~Brain();

	void PutIdea(const int index, const std::string idea);
	const std::string GetIdea(const int index) const;
	void printidea(const int index) const;
	void printbrain() const;
};

#endif