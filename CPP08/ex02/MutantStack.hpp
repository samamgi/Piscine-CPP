/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <ssadi-ou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 09:19:46 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/21 11:39:19 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class	MutantStack	:	public std::stack<T>
{
	public : 
		typedef typename std::stack<T>::container_type::iterator	iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		MutantStack(){};
		MutantStack(MutantStack const &copy) : std::stack<T>(copy){};
		MutantStack(std::stack<T> const &copy) : std::stack<T>(copy){};
		~MutantStack(){};

		MutantStack	&operator=(MutantStack const &copy)
		{
			if (this == &copy)
				return (*this);
			this->std::stack<T>::operator=(copy);
			return (*this);
		};

		iterator	begin()
		{
			return (this->c.begin());
		};

		iterator	end()
		{
			return (this->c.end());
		};

		const_iterator	begin()	const
		{
			return (this->c.begin());
		}

		const_iterator	end()	const
		{
			return (this->c.end());
		}
};

#endif
