/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:16:24 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/10/02 09:16:25 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::raw_bits = 8;

Fixed::Fixed(): raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor Called" << std::endl;
}

Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called" << std::endl;
    Fixed::raw = value * (1 << raw_bits);
}

Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;
    const float tmp = (float)(1 << raw_bits);
    Fixed::raw = (int)(roundf(value * tmp));
}

int   Fixed::toInt(void)    const
{
    return (Fixed::raw >> raw_bits);
}

float   Fixed::toFloat(void)   const
{
    return ((float)Fixed::raw / (1 << raw_bits));
}

Fixed&  Fixed::operator=(const Fixed& value)
{
    std::cout << "Copy assignment operator called" << std::endl;
    Fixed::raw = value.raw;
    return (*this);
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    Fixed::raw = copy.raw;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (Fixed::raw);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    Fixed::raw = raw;
}

std::ostream&   operator<<(std::ostream& output, const Fixed& res)
{
    output << res.toFloat();
    return (output);
}