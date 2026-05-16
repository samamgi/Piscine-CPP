/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:25:25 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/20 20:55:27 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class	Span
{
	private:
		unsigned int		N;
		std::vector<int>	vc;
	public:
		Span();
		Span(unsigned int new_N);
		Span(Span const &copy);
		~Span();

		Span	&operator=(Span const &copy);

		void	addNumber(int number);

		template <typename iterator>
		void	addNumber(iterator begin, iterator end)
		{
			while (begin != end)
        		{
                		this->addNumber(*begin);
                		begin++;
        		}

		};

		unsigned int	shortestSpan()	const;
		unsigned int	longestSpan()	const;
		
		unsigned int	getN()	const;
		std::vector<int>	&getVC();

		class	NoValuesException : public std::exception
		{
			public:
				virtual const char	*what()	const throw();
		};
		class	fullException : public std::exception
		{
			public:
				virtual const char	*what() 	const throw();
		};
};

#endif
