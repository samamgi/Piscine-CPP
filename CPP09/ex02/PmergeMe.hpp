/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 18:42:04 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/29 18:42:06 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cerrno>
# include <climits>
# include <cstdlib>
# include <deque>
# include <iomanip>
# include <iostream>
# include <vector>
# include <ctime>

class PmergeMe
{
  private:
	std::vector<int> vec;
	std::deque<int> deq;

  public:
	PmergeMe();
	PmergeMe(PmergeMe const &copy);
	~PmergeMe();

	PmergeMe &operator=(PmergeMe const &copy);

	void checkvec(char **av);
	void checkdeq(char **av);

	bool    set_containersvec(char *av);
	bool    set_containersdeq(char *av);

	bool    set_argsvec(char **av);
	bool    set_argsdeq(char **av);

	void printvecbefore();

	std::vector<int> sortvector(std::vector<int> v);

	void printvecafter(std::vector<int> v);

	std::deque<int> sortdeque(std::deque<int> input);

	void printdeqbefore(std::deque<int> v);

	void printdeqafter(std::deque<int> v);

	std::vector<int>    GetVec() const;
	std::deque<int>    GetDeq() const;
};

#endif
