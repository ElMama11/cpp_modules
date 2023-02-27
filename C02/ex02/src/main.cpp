/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:21:00 by mverger           #+#    #+#             */
/*   Updated: 2023/02/27 18:44:13 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "classes/Fixed.hpp"


int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

			std::cout << "\nCUSTOM TESTS:\n" << std::endl;
	
			Fixed c(4);
			Fixed const d(2);
		
			std::cout << "c: " << c << std::endl;
			std::cout << "d: " << d << std::endl;
		
			std::cout << "c++: " << c++ << std::endl;
			std::cout << "c: " << c << std::endl;
			std::cout << "++c: " << ++c << std::endl;
			std::cout << "c: " << c << std::endl;
		
			std::cout << "c + d: " << c + d << std::endl;
			std::cout << "d + c: " << d + c << std::endl;
		
			std::cout << "c - d: " << c - d << std::endl;
			std::cout << "d - c: " << d - c << std::endl;
		
			std::cout << "c * d: " << c * d << std::endl;
			std::cout << "d * c: " << d * c << std::endl;
		
			std::cout << "c / d: " << c / d << std::endl;
			std::cout << "d / c: " << d / c << std::endl;

			// std::cout << "c < d: " << c <= d << std::endl;
			// std::cout << "d < c: " << d <= c << std::endl;

			// std::cout << "c > d: " << c >= d << std::endl;
			// std::cout << "d > c: " << d >= c << std::endl;

			// std::cout << "c <= d: " << c <= d << std::endl;
			// std::cout << "d <= c: " << d <= c << std::endl;

			// std::cout << "c >= d: " << c >= d << std::endl;
			// std::cout << "d >= c: " << d >= c << std::endl;
		
			std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;
			std::cout << "max(d, c): " << Fixed::max(c, d) << std::endl;
		
			std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
			std::cout << "min(d, c): " << Fixed::min(c, d) << std::endl;
	return 0;
}
