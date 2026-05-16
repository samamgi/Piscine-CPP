/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:47:41 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/13 21:35:33 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int const tab[5] = {1, -2, 3, -4, 5};
	std::string	tab2[5] = {"hello", "world", "42", "DSA", "CPP"};

	std::cout << "const function called with int const array read_only:" << std::endl << "-------------------------------------------------------------" << std::endl;
	std::cout << "array ptr before iter : " << tab << std::endl;
	std::cout << "before const iter, tab[5]: " << tab[0] << " " << tab[1] << " " << tab[2] << " " << tab[3] << " " << tab[4] << std::endl;
	iter(tab, 5, func_const);
	std::cout << "array ptr after iter : " << tab << std::endl;
	std::cout << "after const iter, tab[5]: " << tab[0] << " " << tab[1] << " " << tab[2] << " " << tab[3] << " " << tab[4] << std::endl << std::endl;

	std::cout << "non const function called with string array read_write:" << std::endl << "-------------------------------------------------------------" << std::endl;
	std::cout << "array ptr before iter : " << tab2 << std::endl;
	std::cout << "before non const iter, tab de string: " << tab2[0] << " " << tab2[1] << " " << tab2[2] << " " << tab2[3] << " " << tab2[4] << std::endl;
	iter(tab2, 5, func_nonconst);
	std::cout << "array ptr after iter : " << tab2 << std::endl;
	std::cout << "after non const iter, tab de string: " << tab2[0] << " " << tab2[1] << " " << tab2[2] << " " << tab2[3] << " " << tab2[4] << std::endl << std::endl;
}
