#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <stdlib.h>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed &operator=(const Fixed &rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

#endif