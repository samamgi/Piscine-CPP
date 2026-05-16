/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <ssadi-ou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 18:45:04 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/28 14:22:29 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 2;
	}
	BTC	dflt;
	std::string	filename = av[1];
	try
	{
		dflt.loadDataBase("data.csv");
	}
	catch (std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	try
	{
		dflt.getRates(filename);
	}
	catch (std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
