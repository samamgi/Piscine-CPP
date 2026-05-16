/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:19:41 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/10/01 01:20:13 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		Harl	harl;

// 		harl.complain(av[1]);
// 	}
// }

int	main(void)
{
	std::string	input;
	Harl	harl;

	while (1)
	{
		std::cout << "prompt$>";
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			break ;
		}
		if (input == "exit")
			break;
		harl.complain(input);
	}
}
