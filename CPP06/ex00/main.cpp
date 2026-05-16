/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 20:01:38 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/11 20:02:21 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cerr << "Usage: " << av[0] << " <input>" << std::endl, EXIT_FAILURE);
    ScalarConvert::convert(av[1]);
    return (EXIT_SUCCESS);
}

