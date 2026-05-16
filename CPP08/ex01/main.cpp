/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <ssadi-ou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 18:45:04 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/20 21:03:20 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int	main(void)
{
	srand(time(NULL));
	std::vector<int> v;
	for (int i = 0; i < 10000; i++)
		v.push_back((rand()) % 9);
	Span nl(10000);
	try
	{
		nl.addNumber(v.begin(), v.end());
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::vector<int>::iterator i = nl.getVC().begin();
	try
	{
		std::cout << "Shortest range: " << nl.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "Longest range: " << nl.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	while (i != nl.getVC().end())
	{
		std::cout << *i << " ";
		i++;
	}
	std::cout << std::endl;

	// Span	sp;
	// sp = Span(5);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	// return (0);
}
