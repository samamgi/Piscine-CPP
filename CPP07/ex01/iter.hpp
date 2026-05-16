/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:59:30 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/13 21:32:20 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iomanip>
#include <iostream>
#include <cstdlib>

template <typename T>
void	iter(T const *tab, unsigned const int size, void(*funct)(T const &))
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		funct(tab[i]);
		i++;
	}
}
template <typename T>
void    iter(T *tab, unsigned const int size, void(*funct)(T &))
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		funct(tab[i]);
		i++;
	}
}
template <typename T>
void	func_const(T const &value)
{

	if (value < 0)
		std::cout << value << " is negatif" << std::endl;
	else
		std::cout << value << " is positif" << std::endl;
}

template <typename T>
void	func_nonconst(T &value)
{
	size_t	i;

	i = 0;
	while (i < value.size())
	{
		if (value[i] >= 97 && value[i] <= 122)
			value[i] -= 32;
		i++;
	}
}

#endif
