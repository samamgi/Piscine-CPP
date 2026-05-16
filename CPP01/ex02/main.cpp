/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 22:30:40 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/09/27 22:35:15 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string str;
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	str = "HI THIS IS BRAIN";

	std::cout << "memory adress of string   :" << &str << std::endl;
	std::cout << "memory adress held by ptr :" << stringPTR << std::endl;
	std::cout << "memory adress held by ref :" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "content of string   :" << str << std::endl;
	std::cout << "content held by ptr :" << *stringPTR << std::endl;
	std::cout << "content held by ref :" << stringREF << std::endl;
}
