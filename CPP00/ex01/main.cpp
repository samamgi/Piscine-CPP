/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 04:47:30 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/09/19 04:48:44 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <stdlib.h>

bool	is_index(std::string str)
{
	int	i;

	i = 0;
	while (str[i] && ((str[i] >= 7 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	while (str[i] && ((str[i] >= 7 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i])
		return (false);
	return (true);
}

int	main(void)
{
	PhoneBook	Repertoire;

	std::string input;
	while (1)
	{
		std::cout << "PhoneBook $> ";
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			break ;
		}
		if (input == "EXIT")
			break ;
		if (input == "ADD")
		{
			if (Repertoire.add_contact() == 2)
				break ;
			continue ;
		}
		if (input == "SEARCH")
		{
			Repertoire.print_contact_list();
			std::cout << "Enter the index of the contact you want to view: ";
			if (!std::getline(std::cin, input))
			{
				std::cout << std::endl;
				break ;
			}
			if (is_index(input) == true)
				Repertoire.print_contact_index(std::atoi(input.c_str()));
			else
			{
				std::cout << (std::cin.fail()
					|| std::cin.eof() ? "\n" : "") << "Invalid index" << std::endl;
			}
			continue ;
		}
		else
		{
			std::cout << (std::cin.fail()
				|| std::cin.eof() ? "\n" : "") << "Invalid Input" << std::endl;
		}
	}
}
