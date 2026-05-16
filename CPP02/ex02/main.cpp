/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadi-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:16:02 by ssadi-ou          #+#    #+#             */
/*   Updated: 2025/10/02 09:16:03 by ssadi-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed	a;

	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return (0);
}

// int main() {
//     std::cout.setf(std::ios::fixed);
//     std::cout.precision(8); // pour bien voir les pas de 1/256 = 0.00390625

//     std::cout << "=== Ctors / toFloat / toInt ===\n";
//     Fixed a;                 // 0
//     Fixed b(10);             // 10.0
//     Fixed c(42.42f);         // ~42.421875 (42.42 * 256 arrondi / 256)
//     Fixed d(b);              // copie de b
//     std::cout << "a=" << a << " (exp 0)\n";
//     std::cout << "b=" << b << " (exp 10)\n";
//     std::cout << "c=" << c << " (exp ~42.421875)\n";
//     std::cout << "d=" << d << " (exp 10)\n";
//     std::cout << "b.toInt()=" << b.toInt() << " (exp 10)\n";
//     std::cout << "c.toInt()=" << c.toInt() << " (exp 42)\n\n";

//     std::cout << "=== Arithmetic (+ - * /) ===\n";
//     Fixed p(3), q(2);
//     std::cout << "p+q=" << (p+q) << " (exp 5)\n";
//     std::cout << "p-q=" << (p-q) << " (exp 1)\n";
//     std::cout << "p*q=" << (p*q) << " (exp 6)\n";
//     std::cout << "p/q=" << (p/q) << " (exp 1.5)\n";
//     Fixed e(5.05f), f(2);
//     Fixed g = e * f;
//     std::cout << "5.05f * 2 = " << g << " (exp ~10.10156250)\n\n";

//     std::cout << "=== Pre/Post ++/-- (pas = 1/256 = 0.00390625) ===\n";
//     Fixed x; // 0
//     std::cout << "x="    << x    << " (exp 0)\n";
//     std::cout << "++x="  << ++x  << " (exp 0.00390625)\n";
//     std::cout << "x="    << x    << " (exp 0.00390625)\n";
//     std::cout << "x++="  << x++  << " (exp 0.00390625)\n";
//     std::cout << "x="    << x    << " (exp 0.00781250)\n";
//     std::cout << "--x="  << --x  << " (exp 0.00390625)\n";
//     std::cout << "x--="  << x--  << " (exp 0.00390625)\n";
//     std::cout << "x="    << x    << " (exp 0)\n\n";

//     std::cout << "=== Comparisons ===\n";
//     Fixed r(1), s(1), t(2);
//     std::cout << std::boolalpha;
//     std::cout << "r==s " << (r==s) << " (exp true)\n";
//     std::cout << "r!=s " << (r!=s) << " (exp false)\n";
//     std::cout << "r<t  " << (r<t)  << " (exp true)\n";
//     std::cout << "t>r  " << (t>r)  << " (exp true)\n";
//     std::cout << "r<=s " << (r<=s) << " (exp true)\n";
//     std::cout << "t>=s " << (t>=s) << " (exp true)\n\n";

//     std::cout << "=== min / max (non-const + const) ===\n";
//     std::cout << "min(b,c)=" << Fixed::min(b,c) << " (exp 10)\n";
//     std::cout << "max(b,c)=" << Fixed::max(b,c) << " (exp ~42.421875)\n";
//     Fixed const cb(b), cc(c);
//     std::cout << "min(cb,cc)=" << Fixed::min(cb,cc) << " (exp 10)\n";
//     std::cout << "max(cb,cc)=" << Fixed::max(cb,cc) << " (exp ~42.421875)\n\n";

//     std::cout << "=== Exemple du sujet ===\n";
//     Fixed A;
//     Fixed const B( Fixed(5.05f) * Fixed(2) );
//     std::cout << A << "\n";
//     std::cout << ++A << "\n";
//     std::cout << A << "\n";
//     std::cout << A++ << "\n";
//     std::cout << A << "\n";
//     std::cout << B << " (exp ~10.10156250)\n";
//     std::cout << Fixed::max(A, B) << " (exp ~10.10156250)\n";

//     return 0;
// }


