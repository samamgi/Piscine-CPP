/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 22:04:42 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/15 20:19:32 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class	Array
{
	private:
		T				*tab;
		unsigned int	len;
	public:
		Array() : tab(NULL), len(0) {};
		Array(unsigned int new_size) : len(new_size)
		{
			tab = new T[len]();
		};
		Array(Array const &copy)
		{
			unsigned int	i;
			this->tab = new T[copy.len];
			this->len = copy.len;
			i = 0;
			while (i < len)
			{
				this->tab[i] = copy.tab[i];
				i++;
			}
		};
		~Array()
		{
			delete [] this->tab;
			this->tab = NULL;
			this->len = 0;
		};

		Array	&operator=(Array const &copy)
		{
			unsigned int	i;
			T	*tmp;

			if (this == &copy)
				return (*this);
			tmp = new T[copy.len];
			i = 0;
			while (i < len)
			{
				tmp[i] = copy.tab[i];
				i++;
			}
			delete [] this->tab;
			this->tab = tmp;
			this->len = copy.len;
			return (*this);
		};
		
		unsigned int	size(void) const
		{
			return (this->len);
		};
	
		class OutOfBoundsException : public std::exception
                {
                        public:
                                virtual const char      *what() const throw()
                                {
                                        return ("Index is out of scope");
                                }
                };

		T			&operator[](unsigned int index)
		{
			if (index >= len)
				throw (Array::OutOfBoundsException());
			return (this->tab[index]);
		};

		T const		&operator[](unsigned int index) const
		{
			if (index >= len)
                                throw (Array::OutOfBoundsException());
			return (this->tab[index]);
		};
};

#endif