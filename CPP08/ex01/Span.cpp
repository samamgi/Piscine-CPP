/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:55:01 by ssadi-ou          #+#    #+#             */
/*   Updated: 2026/04/20 20:55:22 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0), vc()
{
}

Span::Span(unsigned int new_N) : N(new_N), vc()
{
}

Span::Span(Span const &copy) : N(copy.N), vc(copy.vc)
{
}

Span::~Span()
{
}

Span	&Span::operator=(Span const &copy)
{
	this->N = copy.N;
	this->vc = copy.vc;
	return (*this);
}

const char	*Span::NoValuesException::what() const throw()
{
	return ("Not enought values");
}

const char	*Span::fullException::what() const throw()
{
	return ("Span is full");
}

void	Span::addNumber(int number)
{
	if (this->vc.size() < this->N)
		this->vc.push_back(number);
	else
		throw (Span::fullException());
}

unsigned int	Span::getN()	const
{
	return (this->N);
}

std::vector<int>	&Span::getVC()
{
	return this->vc;
}

unsigned int	Span::shortestSpan()	const
{
	int		tmp;
	int		res;
	unsigned int	ret;
	std::vector<int>::size_type	i;
	std::vector<int>::size_type     j;
	
	if ((this->vc).size() < 2)
		throw (Span::NoValuesException());
	i = 0;
	tmp = 0;
	res = vc[0] - vc[1];
	if (res < 0)
		res *= -1;
	while (i < (this->vc).size())
	{
		j = 0;
		while (j < (this->vc).size())
		{
			if (j == i)
			{
				j++;
				continue;
			}
			tmp = vc[i] - vc[j];
			if (tmp < 0)
				tmp *= -1;
			if (tmp < res)
				res = tmp;
			j++;
		}
		i++;
	}
	ret = res;
	return (ret);
}

unsigned int    Span::longestSpan()    const
{
        int             tmp;
        int             res;
        unsigned int    ret;
        std::vector<int>::size_type     i;
        std::vector<int>::size_type     j;

        if ((this->vc).size() < 2)
                throw (Span::NoValuesException());
        i = 0;
        tmp = 0;
        res = vc[0] - vc[1];
        if (res < 0)
                res *= -1;
        while (i < (this->vc).size())
        {
                j = 0;
                while (j < (this->vc).size())
                {
                        if (j == i)
                        {
                                j++;
                                continue;
                        }
                        tmp = vc[i] - vc[j];
                        if (tmp < 0)
                                tmp *= -1;
                        if (tmp > res)
                                res = tmp;
                        j++;
                }
                i++;
        }
        ret = res;
        return (ret);
}
