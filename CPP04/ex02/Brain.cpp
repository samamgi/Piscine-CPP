/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 23:32:17 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/01/26 23:32:18 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrainClass.hpp"

Brain::Brain()
{
    int i;
    
    std::cout << "Brain Constructor Called" << std::endl;
    i = 0;
    while (i < 100)
    {
        Brain::ideas[i] = "Default";
        i++;
    }
}

Brain::Brain(const Brain &copy)
{
    int i;

    std::cout << "Brain Copy Constructor Called" << std::endl;
    i = 0;
    while (i < 100)
    {
        Brain::ideas[i] = copy.ideas[i];
        i++;
    }
}

Brain&  Brain::operator=(const Brain &copy)
{
    int i;

    i = 0;
    while (i < 100)
    {
        this->ideas[i] = copy.ideas[i];
        i++;
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain Destructor Called" << std::endl;
}

void    Brain::PutIdea(const int index, const std::string idea)
{
    if (index >= 0 && index <= 99)
        this->ideas[index] = idea;
    else
        std::cout << "Invalid Brain idea index" << std::endl;
}

const std::string   Brain::GetIdea(const int index) const
{
    if (index >= 0 && index <= 99)
        return (this->ideas[index]);
    else
    {
        std::cout << "Invalid Brain idea index" << std::endl;
        return (NULL);
    }
}

void    Brain::printidea(const int index)  const
{
    if (index >= 0 && index <= 99)
    {
        if (ideas[index] == "Default")
            std::cout << "No idea at index" << std::endl;
        else
            std::cout << ideas[index] << std::endl;
    }
    else
        std::cout << "Invalid Brain idea index" << std::endl;
}

void    Brain::printbrain() const
{
    int i;

    i = 0;
    while (i < 100)
    {
        std::cout << "Idea - " << i << " : ";
        if (Brain::ideas[i] == "Default")
        {
            std::cout << std::endl;
            i++;
        }
        else
            Brain::printidea(i++);
    }
}