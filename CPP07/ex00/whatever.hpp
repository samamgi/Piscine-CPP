/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:36:25 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/13 18:50:07 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>

template <typename T>
void swap(T &a, T &b)
{
	T	tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
T const &min(T const &a, T const &b)
{
	if (b <= a)
		return (b);
	return (a);
}

template <typename T>
T const &max(T const &a, T const &b)
{
	if (b >= a)
		return (b);
	return (a);
}

#endif
