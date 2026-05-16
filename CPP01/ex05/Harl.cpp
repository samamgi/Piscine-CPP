/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:48:20 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/10/01 00:48:21 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl << "I really do!" << std::endl << std::endl;
}
void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn’t put enough bacon in my burger!" << std::endl << "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}
void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming for years, whereas you started working here just last month. " << std::endl << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now. " << std::endl << std::endl;
}

void Harl::complain(std::string level)
{
    int     i;
    void    (Harl::*levels[4])() = {
        &Harl::debug, 
        &Harl::error, 
        &Harl::info, 
        &Harl::warning};
    std::string code[4] = {"DEBUG",
         "ERROR", 
         "INFO", 
         "WARNING"};
    i = 0;
    while (i < 4)
    {
        if (level == code[i])
        {
            (this->*levels[i])();
            return;
        }
        i++;
    }
    std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
}
