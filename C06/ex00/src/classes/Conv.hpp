#ifndef CONV_HPP
# define CONV_HPP

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <limits.h>
#include <float.h>

#define CHAR			1
#define INT				2
#define FLOAT			3
#define DOUBLE			4
#define PSEUDO_LITERAL	5

class Conv
{
	public:
		Conv(void);
		Conv(char * arg);
		Conv(const Conv& cpy);
		virtual ~Conv(void);

		Conv&	operator=(const Conv& rhs);

		std::string output;

	protected:
		class ImpossibleTypeConversation : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("error");
				}
		};

	private:
		char 		*_arg;
		int			_type;

		char		_valueChar;
		int			_valueInt;
		float		_valueFloat;
		double		_valueDouble;
		std::string	_valuePseudoLiteral;

		bool		_charLimit;
		bool		_intLimit;
		bool		_floatLimit;
		bool		_doubleLimit;

		void	_checkType(void);
		bool	_isChar(char *arg);
		bool	_isInt(char *arg);
		bool	_isFloat(char *arg);
		bool	_isDouble(char *arg);
		bool	_isPseudoLiteral(char *arg);

		void	_convert(void);
		void	_charConvert(void);
		void	_intConvert(void);
		void	_floatConvert(void);
		void	_doubleConvert(void);
		void	_pseudoLiteralConvert(void);

		void	_checkLimit(void);

		void	_printValues(void);
		void	_printPseudoLiteral(void);
		void	_printChar(void);
		void	_printInt(void);
		void	_printFloat(void);
		void	_printDouble(void);
};

std::ostream&	operator<<(std::ostream& o, const Conv& i);

#endif