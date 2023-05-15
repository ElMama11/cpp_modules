#ifndef CONV_HPP
# define CONV_HPP

# include <string>
# include <iostream>
# include <cmath>
 # include <sstream>

class Conv
{
	private:
		const std::string _value;

	public:
		Conv();
		Conv(std::string const &value);
		Conv(const Conv &cpy);
		~Conv();

		Conv &operator=(const Conv &rhs);

		std::string const &getValue() const;
		char toChar() const;
		int toInt() const;
		float toFloat() const;
		double toDouble() const;

		class ImpossibleException : public std::exception
		{
			const char *what() const throw()
			{
				return "Impossible";
			}
		};
		class NonDisplayableException : public std::exception
		{
			const char *what() const throw()
			{
				return "Non displayable";
			}
		};
};

std::ostream &operator<<(std::ostream &os, Conv const &Conv);

#endif