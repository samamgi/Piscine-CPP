/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <ssadi-ou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 03:24:18 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/28 03:19:43 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BTC::BTC() : data()
{
}

BTC::BTC(BTC const &copy) : data(copy.data)
{
}

BTC::~BTC()
{
}

BTC &BTC::operator=(BTC const &copy)
{
	if (this == &copy)
		return (*this);
	this->data = copy.data;
	return (*this);
}

void	setdaterate(std::string &date, double &rate, std::string line)
{
	std::string::size_type i = line.find(',');
	if (i == std::string::npos)
		throw(std::runtime_error("Error: invalid data line (missing comma)."));
	date = line.substr(0, i);
	if (i + 1 >= line.size())
		throw(std::runtime_error("Error: invalid data line (missing rate)."));
	rate = std::atof(line.substr(i + 1).c_str());
}

void BTC::loadDataBase(const std::string &filename)
{
	double	rate;

	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		file.close();
		throw(std::runtime_error("Error: could not open data.csv."));
	}
	std::string line;
	std::getline(file, line);
	std::string date;
	while (std::getline(file, line))
	{
		if (!file.is_open())
			throw(std::runtime_error("Error: could not load data.csv."));
		setdaterate(date, rate, line);
		data[date] = rate;
	}
	file.close();
}

bool	checkfirstline(std::string &line)
{
	if (line != "date | value")
	{
		std::cerr << "Error: Invalid format file." << std::endl;
		return (false);
	}
	return (true);
}

bool	checkformat(std::string &line)
{
	bool	point;

	std::string::size_type i = 0;
	std::string::size_type n = line.size();
	/* YYYY */
	while (i < 4)
	{
		if (i >= n || !isdigit(line[i]))
			return (false);
		i++;
	}
	if (i >= n || line[i] != '-')
		return (false);
	i++;
	/* MM */
	while (i < 7)
	{
		if (i >= n || !isdigit(line[i]))
			return (false);
		i++;
	}
	if (i >= n || line[i] != '-')
		return (false);
	if (i < 2 || i > n)
		return (false);
	if ((atoi((line.substr((i - 2), 2)).c_str())) > 12)
		return (false);
	i++;
	/* DD */
	while (i < 10)
	{
		if (i >= n || !isdigit(line[i]))
			return (false);
		i++;
	}
	if (i >= n || line[i] != ' ')
		return (false);
	if (i < 2 || i > n)
		return (false);
	if ((atoi((line.substr((i - 2), 2)).c_str())) > 31)
		return (false);
	i++;
	if (i >= n || line[i] != '|')
		return (false);
	i++;
	if (i >= n || line[i] != ' ')
		return (false);
	i++;
	if (i >= n)
		return (false);
	if (!isdigit(line[i]) && line[i] != '-')
		return (false);
	i++;
	if (i > n && (i > 0 && line[i - 1] == '-'))
		return (false);
	point = false;
	std::string tmp = line;
	if (i == 0 || i - 1 > tmp.size())
		return (false);
	line = line.substr(i - 1);
	/* validate number part in tmp starting from original i */
	while (i < n)
	{
		if (tmp[i] == '.')
		{
			if (point == true)
				return (false);
			point = true;
			if ((i + 1) >= n || !isdigit(tmp[i + 1]))
				return (false);
		}
		else if (!isdigit(tmp[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	checknum(std::string &line, double &rate)
{
	char	*end;
	double	max;

	errno = 0;
	max = std::strtod(line.c_str(), &end);
	if (errno == ERANGE)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	if (max > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	if (max < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	rate = max;
	return (true);
}

bool	bisextile(int year)
{
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	if (year % 4 == 0)
		return true;
	return false;
}

bool	valid_date(int year, int month, int day)
{
	int	yeartab[] = {31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31};
	if (day < 1)
		return false;
	if (month < 1)
		return (false);
	if (month == 2 && bisextile(year))
	{
		if (day > 29)
			return (false);
	}
	else
	{
		if (day > yeartab[month - 1])
			return (false);
	}
	return (true);
}

bool	checkdate(std::string &line)
{
	if (line.size() < 10)
		return (false);
	int	year = std::atoi(line.substr(0, 4).c_str());
	int	month = std::atoi(line.substr(5, 2).c_str());
	int	day	= std::atoi(line.substr(8, 2).c_str());

	return (valid_date(year, month, day));
}

bool	parseline(std::string &line, double &rate)
{
	std::string tmp = line;
	if (line.size() == 0)
		return (false);
	if (checkformat(tmp) == false)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}
	if (checkdate(line) == false)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}
	if (checknum(tmp, rate) == false)
		return (false);
	return (true);
}

bool BTC::isRate(std::string &line)
{
	std::map<std::string, double>::iterator i = this->data.begin();
	std::string::size_type pos = line.find(' ');
	std::string key = (pos == std::string::npos) ? line : line.substr(0, pos);
	while (i != this->data.end())
	{
		if (i->first == key)
			return (true);
		i++;
	}
	return (false);
}

std::string formatDouble(double value)
{
	std::ostringstream oss;

	oss << std::fixed << std::setprecision(10) << value;

	std::string str = oss.str();

	while (str.length() > 1 && str[str.length() - 1] == '0')
		str.erase(str.length() - 1);

	if (!str.empty() && str[str.length() - 1] == '.')
		str.erase(str.length() - 1);

	if (str == "-0")
		str = "0";

	return str;
}

void BTC::printRate(std::string &line, double &rate)
{
	std::map<std::string, double>::iterator i;
	std::string::size_type pos = line.find(' ');
	std::string key = (pos == std::string::npos) ? line : line.substr(0, pos);
	if (isRate(line) == false)
	{
		i = this->data.lower_bound(key);
		if (i == this->data.begin())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			return ;
		}
		i--;
	}
	else
		i = data.find(key);
	std::cout << key << " => " << formatDouble(rate) << " = " << formatDouble((rate * i->second)) << std::endl;
}

void BTC::getRates(std::string const &filename)
{
	double	rate;

	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		file.close();
		throw(std::runtime_error("Error: could not open file."));
	}
	std::string line;
	std::getline(file, line);
	if (checkfirstline(line) == false)
		return ;
	rate = 0;
	while (std::getline(file, line))
	{
		if (parseline(line, rate) == false)
			continue ;
		printRate(line, rate);
	}
	file.close();
}

void BTC::printarg(std::string const &filename)
{
	std::ifstream file(filename.c_str());
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (!file.is_open())
			throw(std::runtime_error("Error: could not laod arg file."));
		std::cout << line << std::endl;
	}
	file.close();
}

void BTC::printDataBase(void)
{
	std::map<std::string, double>::iterator i = this->data.begin();
	while (i != this->data.end())
	{
		std::cout << i->first << ": " << i->second << std::endl;
		i++;
	}
}
