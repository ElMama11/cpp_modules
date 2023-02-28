#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <stdlib.h>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int nb);
		Fixed(const float nb);
		~Fixed();

		Fixed &operator=(const Fixed &rhs);
		bool operator>(Fixed &fixed) const;
		bool operator<(Fixed &fixed) const;
		bool operator>=(Fixed &fixed) const;
		bool operator<=(Fixed &fixed) const;
		bool operator==(Fixed &fixed) const;
		bool operator!=(Fixed &fixed) const;
		// Arithmetic Operators
		float operator+(Fixed &fixed) const;
		float operator-(Fixed &fixed) const;
		float operator*(Fixed fixed) const;
		float operator/(Fixed &fixed) const;
		// pre-increment Operators
		Fixed operator++();
		Fixed operator--();
		// post-increment Operators
		Fixed operator++(int);
		Fixed operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed &min(Fixed &first, Fixed &second);
		static const Fixed &min(Fixed const &first, Fixed const &second);
		static Fixed &max(Fixed &first, Fixed &second);
		static const Fixed &max(Fixed const &first, Fixed const &second);
		
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);
#endif