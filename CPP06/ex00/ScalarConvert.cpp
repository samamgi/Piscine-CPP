/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <ssadi-ou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 09:32:22 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/11 19:38:04 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert()
{
}

ScalarConvert::ScalarConvert(ScalarConvert const &)
{
}

ScalarConvert::~ScalarConvert()
{
}

ScalarConvert    &ScalarConvert::operator=(ScalarConvert const &)
{
	return (*this);
}

int	check(std::string &str)
{
	size_t	point;
	char 	*end = NULL;
	errno = 0;
	std::string::size_type i = 0;
	
	if (str == "" || str.empty() || str[i] <= 0 || str[i] > 127)
		return (0);
	if (str.size() == 1)
	{
		if (isdigit(str[0]))
			return (2);
		return (1);
	}
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff"
		|| str == "-inff" || str == "-inf")
	{
		if (str == "nanf" || str == "+inff" || str == "-inff")
			return (3);
		return (4);
	}
	if (str[0] == '+' || str[0] == '-')
		i++;
	point = 0;
	while (str[i])
	{
		if (str[i] == '.' && (!(str[i + 1])))
		{
			long val = strtol(str.c_str(), &end, 10);
			if (errno == ERANGE || val > INT_MAX || val < INT_MIN)
				return (0);
			return (4);
		}
		if (str[i] == 'f')
		{
			if (!(str[i + 1]))
			{
				if (point == 0)
					return (0);
				long val = strtol(str.c_str(), &end, 10);
				if (errno == ERANGE || val > INT_MAX || val < INT_MIN)
					return (0);
				return (3);
			}
			break ;
		}
		if (str[i] == '.')
		{
			if (point == 0)
			{
				point = 1;
				i++;
				continue ;
			}
			else
				return (0);
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	if (str[i] == 'f' && str[i + 1])
		return (0);
	if (point == 0)
	{
		long val = strtol(str.c_str(), &end, 10);
		if (errno == ERANGE || val > INT_MAX || val < INT_MIN)
			return (0);
		return (2);
	}
	long val = strtol(str.c_str(), &end, 10);
	if (errno == ERANGE || val > INT_MAX || val < INT_MIN)
		return (0);
	return (4);
}

void ScalarConvert::convert(std::string const &str)
{
	int result;
	std::string res = str;
	result = check(res);

	if (result == 0)
	{
		std::cerr << "Invalid input." << std::endl;
		return;
	}
	if (result == 1)
	{
		char char_res = static_cast<char>(res[0]);
		if (!isprint(char_res))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << char_res << "'" << std::endl;
		int int_res = static_cast<int>(res[0]);
		std::cout << "int: " << int_res << std::endl;
		float float_res = static_cast<float>(int_res);
		std::cout << "float: " << std::fixed << std::setprecision(1) << float_res << "f" << std::endl;
		double double_res = static_cast<double>(int_res);
		std::cout << "double: " << std::fixed << std::setprecision(1) << double_res << std::endl;
	}
	if (result == 2)
	{
		int int_res = atoi(res.c_str());
		if (int_res < 32 || int_res > 126)
		{
			if (int_res == 127 || (int_res >= 0 && int_res <= 31))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: impossible" << std::endl;
		}
		else
			std::cout << "char: '" << static_cast<char>(int_res) << "'" << std::endl;
		std::cout << "int: " << int_res << std::endl;
		float float_res = static_cast<float>(int_res);
		std::cout << "float: " << std::fixed << std::setprecision(1) << float_res << "f" << std::endl;
		double double_res = static_cast<double>(int_res);
		std::cout << "double: " << std::fixed << std::setprecision(1) << double_res << std::endl;
	}
	if (result == 3)
	{
		 if (res == "nanf" || res == "+inff" || res == "-inff")
		 {
		 	std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (res == "nanf")
			{
				std::cout << "float: nanf" << std::endl;
				std::cout << "double: nan" << std::endl;
			}
			else if (res == "+inff")
			{
				std::cout << "float: +inff" << std::endl;
				std::cout << "double: +inf" << std::endl;
			}
			else
			{
				std::cout << "float: -inff" << std::endl;
				std::cout << "double: -inf" << std::endl;
			}
			return;
		}
		res.erase(res.size() - 1);
		float float_res = strtof(res.c_str(), NULL);
		if (float_res < 32 || float_res > 126)
		{
			if (float_res == 127 || (float_res >= 0 && float_res <= 31))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: impossible" << std::endl;
		}
		else
			std::cout << "char: '" << static_cast<char>(float_res) << "'" << std::endl;
		long int_res = static_cast<long>(float_res);
		if (int_res > INT_MAX || int_res < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << int_res << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << float_res << "f" << std::endl;
		double double_res = static_cast<double>(float_res);
		std::cout << "double: " << std::fixed << std::setprecision(1) << double_res << std::endl;
	}
	if (result == 4)
	{
		if (res == "nan" || res == "+inf" || res == "-inf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (res == "nan")
			{
				std::cout << "float: nanf" << std::endl;
				std::cout << "double: nan" << std::endl;
			}
			else if (res == "+inf")
			{
				std::cout << "float: +inff" << std::endl;
				std::cout << "double: +inf" << std::endl;
			}
			else
			{
				std::cout << "float: -inff" << std::endl;
				std::cout << "double: -inf" << std::endl;
			}
			return;
		}
		double double_res = strtod(res.c_str(), NULL);
		if (double_res < 32 || double_res > 126)
		{
			if (double_res == 127 || (double_res >= 0 && double_res <= 31))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: impossible" << std::endl;
		}
		else
			std::cout << "char: '" << static_cast<char>(double_res) << "'" << std::endl;
		long int_res = strtol(res.c_str(), NULL, 10);
		if (int_res > INT_MAX || int_res < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << int_res << std::endl;
		float float_res = static_cast<float>(double_res);
		std::cout << "float: " << std::fixed << std::setprecision(1) << float_res << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << double_res << std::endl;
	}
}
