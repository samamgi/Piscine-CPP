/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <ssadi-ou@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 18:45:04 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/29 18:38:51 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	PmergeMe	tri;
	clock_t		end = 0;
	double		time_vec = 0.0;
	double		time_deq = 0.0;

	if (ac < 2)
	{
		std::cerr << "Error" << std::endl;
		return (2);
	}
	try
	{
        clock_t start = clock();
		tri.checkvec(&av[1]);
        std::vector<int> sorted_vec = tri.sortvector(tri.GetVec());
        end = clock();
        time_vec = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000.0;
	}
    catch (std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
    try
    {
        clock_t start = clock();
        tri.checkdeq(&av[1]);
        std::deque<int> sorted_deq = tri.sortdeque(tri.GetDeq());
        end = clock();
        time_deq = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000.0;
		tri.printvecbefore();
		tri.printdeqafter(sorted_deq);
	}
	catch (std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
    std::cout << "Time to process a range of " << tri.GetVec().size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << time_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << tri.GetDeq().size() << " elements with std::deque : " << std::fixed << std::setprecision(5) << time_deq << " us" << std::endl;
	return (0);
}
