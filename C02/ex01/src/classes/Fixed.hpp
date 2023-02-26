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
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);
#endif