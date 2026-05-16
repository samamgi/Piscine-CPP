/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:16:20 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/10/02 09:16:22 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
# define Fixed_HPP

# include <cmath>
# include <iomanip>
# include <iostream>

class Fixed
{
  private:
	int raw;
	int const static raw_bits;

  public:
	Fixed();
	Fixed(int const value);
	Fixed(float const value);
	Fixed(const Fixed &copy);
	~Fixed();
	Fixed &operator=(const Fixed &value);
	int getRawBits(void) const;
	void setRawBits(int const Raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &output, const Fixed &res);

#endif