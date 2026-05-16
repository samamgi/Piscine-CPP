/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <ssadi-ou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 03:24:14 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/28 03:15:18 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <cctype>
# include <cstdlib>
# include <fstream>
# include <iomanip>
# include <iostream>
# include <map>
# include <sstream>
# include <stdexcept>

class BTC
{
  private:
	std::map<std::string, double> data;

  public:
	BTC();
	BTC(BTC const &copy);
	~BTC();

	BTC &operator=(BTC const &copy);

	void loadDataBase(const std::string &filename);

	void getRates(const std::string &filename);


	bool	isRate(std::string &line);
	void	printRate(std::string &line, double &rate);

	void printDataBase();
	void	printarg(std::string const &filename);
};

#endif
