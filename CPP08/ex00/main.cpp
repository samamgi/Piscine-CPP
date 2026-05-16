/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <ssadi-ou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 18:45:04 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/19 19:17:22 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int	main(void)
{
	int	i;
	int	to_find;
	int	not_found;

	std::vector<int> v;
	std::list<int> cl;
	std::deque<int> d;
	i = 0;
	while (i < 10)
	{
		v.push_back(i);
		cl.push_back(i);
		d.push_back(i);
		i++;
	}
	to_find = 5;
	const std::vector<int> cv(v);
	try
	{
		std::vector<int>::const_iterator res = easyfind(cv, to_find);
		std::cout << "vector : " << std::endl;
		std::cout << "Found value: " << *res << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	not_found = 15;
	try
	{
		std::vector<int>::const_iterator res = easyfind(cv, not_found);
		std::cout << "Found value: " << *res << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-----------------------------" << std::endl;
	try
	{
		std::list<int>::const_iterator res = easyfind(cl, to_find);
		std::cout << "list : " << std::endl;
		std::cout << "Found value: " << *res << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::list<int>::const_iterator res = easyfind(cl, not_found);
		std::cout << "Found value: " << *res << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "-----------------------------" << std::endl;
	try
	{
		std::deque<int>::iterator res = easyfind(d, to_find);
		std::cout << "deque : " << std::endl;
		std::cout << "Found value: " << *res << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::deque<int>::iterator res = easyfind(d, not_found);
		std::cout << "Found value: " << *res << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
