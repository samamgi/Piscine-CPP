/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:01:33 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/09/19 18:01:16 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() : index(0), count(0)
{
}

int PhoneBook::add_contact()
{
	int	code;

	code = contact[index].set_contact();
	if (code == 2)
		return (code);
	index++;
	if (count != 8)
		count++;
	if (index > 7)
		index = 0;
	return (0);
}

void PhoneBook::print_contact_index(int i)
{
	if (i <= 0 || count == 0)
		std::cout << "Invalid index" << std::endl;
	else if (i > count)
		std::cout << "Invalid index" << std::endl;
	else
		contact[i - 1].put_contact_index();
}

void PhoneBook::print_contact_list()
{
	int	i;

	i = 1;

	while (i <= count)
	{
		std::cout << "|" << std::setw(10) << "Index"
					<< "|" << std::setw(10) << "First Name"
					<< "|" << std::setw(10) << "Last Name"
					<< "|" << std::setw(10) << "Nickname"
					<< "|" << std::endl;
		contact[i - 1].put_contact_list(i);
		i++;
	}
}
