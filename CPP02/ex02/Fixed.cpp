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
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor Called" << std::endl;
}

Fixed::Fixed(int const value)
{
    // std::cout << "Int constructor called" << std::endl;
    Fixed::raw = value * (1 << raw_bits);
}

Fixed::Fixed(float const value)
{
    // std::cout << "Float constructor called" << std::endl;
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
    // std::cout << "Copy assignment operator called" << std::endl;
    Fixed::raw = value.getRawBits();
    return (*this);
}

Fixed::Fixed(const Fixed& copy)
{
    // std::cout << "Copy constructor called" << std::endl;
    Fixed::raw = copy.raw;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (Fixed::raw);
}

void    Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    Fixed::raw = raw;
}

std::ostream&   operator<<(std::ostream& output, const Fixed& res)
{
    output << res.toFloat();
    return (output);
}

bool    Fixed::operator<(Fixed const& value)    const
{
    return (Fixed::getRawBits() < value.getRawBits());
}

bool    Fixed::operator>(Fixed const& value)    const
{
    return (Fixed::getRawBits() > value.getRawBits());
}

bool    Fixed::operator>=(Fixed const&value)    const
{
    return (Fixed::getRawBits() >= value.getRawBits());
}

bool    Fixed::operator<=(Fixed const&value)    const
{
    return (Fixed::getRawBits() <= value.getRawBits());
}

bool    Fixed::operator==(Fixed const&value)    const
{
    return (Fixed::getRawBits() == value.getRawBits());
}

bool    Fixed::operator!=(Fixed const&value)    const
{
    return (Fixed::getRawBits() != value.getRawBits());
}

Fixed   Fixed::operator+(Fixed const &value) const
{
    Fixed   res;

    res.setRawBits(Fixed::getRawBits() + value.getRawBits());
    return (res);
}

Fixed   Fixed::operator-(Fixed const &value) const
{
    Fixed   res;

    res.setRawBits(Fixed::getRawBits() - value.getRawBits());
    return (res);
}

Fixed   Fixed::operator*(Fixed const& value) const
{
    Fixed       ret;
    long long   res;

    res = (long long)(Fixed::getRawBits() * value.getRawBits());
    ret.setRawBits((int)(res >> raw_bits));
    return (ret);
}

Fixed   Fixed::operator/(Fixed const& value) const
{
    Fixed   ret;
    long long   res;

    if (value.getRawBits() == 0)
    {
        std::cout << "No division by zero!" << std::endl;
        ret.setRawBits(0);
        return(ret);
    }
    res = (long long)(Fixed::getRawBits() << raw_bits);
    ret.setRawBits((int)(res / value.getRawBits()));
    return (ret);
}

Fixed&  Fixed::operator++()
{
    (Fixed::raw)++;
    return (*this);
}

Fixed  Fixed::operator++(int)
{
    Fixed   tmp;

    (Fixed::raw)++;
    return (tmp);
}

Fixed&  Fixed::operator--()
{
    (Fixed::raw)--;
    return (*this);
}

Fixed  Fixed::operator--(int)
{
    Fixed   tmp;

    (Fixed::raw)--;
    return (tmp);
}

Fixed&   Fixed::min(Fixed& a, Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return(a);
    return (b);
}

const Fixed&   Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return(a);
    return (b);
}

Fixed&   Fixed::max(Fixed& a, Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return(a);
    return (b);
}

const Fixed&   Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return(a);
    return (b);
}