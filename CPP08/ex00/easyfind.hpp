/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <ssadi-ou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 18:45:19 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/19 19:15:42 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <stdexcept>

template <typename T>
typename T::iterator  easyfind(T& container, int const to_find)
{
	typename T::iterator res = std::find(container.begin(), container.end(), to_find);
	if (res != container.end())
		return (res);
	else
	{
		throw (std::out_of_range("Did not find value"));
	}
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int const to_find)
{
	typename T::const_iterator res = std::find(container.begin(), container.end(), to_find);
	if (res != container.end())
		return (res);
	else
	{
		throw (std::out_of_range("Did not find value"));
	}
}

#endif
