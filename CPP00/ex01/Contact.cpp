/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:07:47 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/09/19 18:09:06 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <iomanip>
#include <iostream>
#include <limits.h>

Contact::Contact() : first_name(""), last_name(""), nickname(""),
	phone_number(""), darkest_secret("")
{
}

void	clean_string(std::string &str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (isspace(str[i]))
			str[i] = 32;
		if (!isprint(str[i]))
			str[i] = '^';
		i++;
	}
}

bool	is_empty(std::string &str)
{
	int	i;

	i = 0;
	clean_string(str);
	while (str[i])
	{
		if (!std::isspace(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int Contact::set_contact()
{
	while (1)
	{
		std::cout << "first_name : ";
		if (!std::getline(std::cin, first_name))
		{
			std::cout << std::endl;
			return (2);
		}
		if (is_empty(first_name) == true)
		{
			std::cout << (std::cin.fail()
				|| std::cin.eof() ? "\n" : "") << "first_name is empty" << std::endl;
			continue ;
		}
		break ;
	}
	std::cout << (std::cin.fail() || std::cin.eof() ? "\n" : "");
	while (1)
	{
		std::cout << "last_name : ";
		if (!std::getline(std::cin, last_name))
		{
			std::cout << std::endl;
			return (2);
		}
		if (is_empty(last_name) == true)
		{
			std::cout << (std::cin.fail()
				|| std::cin.eof() ? "\n" : "") << "last_name is empty" << std::endl;
			continue ;
		}
		break ;
	}
	std::cout << (std::cin.fail() || std::cin.eof() ? "\n" : "");
	while (1)
	{
		std::cout << "nickname : ";
		if (!std::getline(std::cin, nickname))
		{
			std::cout << std::endl;
			;
			return (2);
		}
		if (is_empty(nickname) == true)
		{
			std::cout << (std::cin.fail()
				|| std::cin.eof() ? "\n" : "") << "nickname is empty" << std::endl;
			continue ;
		}
		break ;
	}
	std::cout << (std::cin.fail() || std::cin.eof() ? "\n" : "");
	while (1)
	{
		std::cout << "phone_number : ";
		if (!std::getline(std::cin, phone_number))
		{
			std::cout << std::endl;
			return (2);
		}
		if (is_empty(phone_number) == true)
		{
			std::cout << (std::cin.fail()
				|| std::cin.eof() ? "\n" : "") << "phone_number is empty" << std::endl;
			continue ;
		}
		break ;
	}
	std::cout << (std::cin.fail() || std::cin.eof() ? "\n" : "");
	while (1)
	{
		std::cout << "darkest_secret : ";
		if (!std::getline(std::cin, darkest_secret))
		{
			std::cout << std::endl;
			return (2);
		}
		if (is_empty(darkest_secret) == true)
		{
			std::cout << (std::cin.fail()
				|| std::cin.eof() ? "\n" : "") << "darkest_secret is empty" << std::endl;
			continue ;
		}
		break ;
	}
	std::cout << (std::cin.fail() || std::cin.eof() ? "\n" : "");
	return (0);
}

std::string truncateField(const std::string &field)
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

void Contact::put_contact_list(int i) const
{
	std::cout << "|" << std::setw(10) << i << "|" << std::setw(10) << truncateField(first_name) << "|" << std::setw(10) << truncateField(last_name) << "|" << std::setw(10) << truncateField(nickname) << "|" << std::endl;
}

void Contact::put_contact_index() const
{
	std::cout << "first_name : " << first_name << std::endl;
	std::cout << "last_name : " << last_name << std::endl;
	std::cout << "nickname : " << nickname << std::endl;
	std::cout << "phone_number : " << phone_number << std::endl;
	std::cout << "darkest_secret : " << darkest_secret << std::endl;
}