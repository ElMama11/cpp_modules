/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conv.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:27:01 by mverger           #+#    #+#             */
/*   Updated: 2023/06/02 18:40:27 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conv.hpp"

Conv::Conv(void)
{
	std::cout << "Conv default constructor called" << std::endl;
	return ;
}

Conv::Conv(char * arg) : _arg(arg)
{
	output = arg;
	_checkType();
	_checkLimit();
	_convert();
	_printValues();
	return ;
}

Conv::Conv(const Conv& cpy)
{
	std::cout << "Conv copy constructor called" << std::endl;
	*this = cpy;
	return ;
}

Conv::~Conv(void)
{
	return ;
}

Conv& Conv::operator=(const Conv& rhs)
{
	if (this != &rhs)
	{
		_arg = rhs._arg;
		_type = rhs._type;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, const Conv& i)
{
	o << i.output;
	return o;
}

void	Conv::_checkType(void)
{
	if (_isChar(_arg))
		_type = CHAR;
	else if (_isInt(_arg))
		_type = INT;
	else if (_isFloat(_arg))
		_type = FLOAT;
	else if (_isDouble(_arg))
		_type = DOUBLE;
	else if (_isPseudoLiteral(_arg))
		_type = PSEUDO_LITERAL;
	else
		throw Conv::ImpossibleTypeConversation();
}

bool	Conv::_isChar(char *arg)
{
	if (arg[1] == '\0' && 
		((arg[0] >= '!' && arg[0] <= '/') ||
		(arg[0] >= ':' && arg[0] <= '~')))
		return (true);
	return (false);
}

bool	Conv::_isInt(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-')
		i++;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

bool	Conv::_isFloat(char *arg)
{
	int i = 0;
	bool isPoint = false;

	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if ((arg[i] < '0' || arg[i] > '9') && arg[i] != '.' && arg[i] != 'f')
			return (false);
		if (arg[i] == '.' && isPoint)
			return (false);
		if (arg[i] == 'f' && (arg[i + 1] != '\0' || !isPoint))
			return (false);
		if (arg[i] == '.')
			isPoint = true;
		i++;
	}
	if (arg[i - 1] == 'f')
		return (true);
	return (false);
}

bool	Conv::_isDouble(char *arg)
{
	int i = 0;
	bool isPoint = false;

	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if ((arg[i] < '0' || arg[i] > '9') && arg[i] != '.')
			return (false);
		if (arg[i] == '.' && isPoint)
			return (false);
		if (arg[i] == '.')
			isPoint = true;
		i++;
	}
	return (true);
}

bool	Conv::_isPseudoLiteral(char *arg)
{
	std::string  pseudoLit = arg;
	if (pseudoLit == "-inff" || pseudoLit == "+inff" || pseudoLit == "nanf" ||
		pseudoLit == "-inf" || pseudoLit == "+inf" || pseudoLit == "nan")
		return (true);
	return (false);
}

void	Conv::_checkLimit(void)
{
	_charLimit = false;
	_intLimit = false;
	_floatLimit = false;
	_doubleLimit = false;
	double value = strtod(_arg, NULL);
	if (value < 0 || value > 127)
		_charLimit = true;
	if (value < INT_MIN || value > INT_MAX)
		_intLimit = true;
	if (value < -FLT_MAX|| value > FLT_MAX)
		_floatLimit = true;
	if (value < -DBL_MAX || value > DBL_MAX)
		_doubleLimit = true;
} 

void	Conv::_convert(void)
{
	std::cout << std::fixed << std::setprecision(1);
	switch (_type)
	{
		case CHAR:
			_charConvert();
			break;
		case INT:
			_intConvert();
			break;
		case FLOAT:
			_floatConvert();
			break;
		case DOUBLE:
			_doubleConvert();
			break;
		case PSEUDO_LITERAL:
			_pseudoLiteralConvert();
			break;
		default:
			throw Conv::ImpossibleTypeConversation();
	}
}

void	Conv::_charConvert(void) 
{
	_valueChar = _arg[0];
	_valueInt = static_cast<int>(_valueChar);
	_valueFloat = static_cast<float>(_valueChar);
	_valueDouble = static_cast<double>(_valueChar);
}

void	Conv::_intConvert(void) 
{
	_valueInt = atoi(_arg);
	_valueChar = static_cast<char>(_valueInt);
	_valueFloat = static_cast<float>(_valueInt);
	_valueDouble = static_cast<double>(_valueInt);
}

void	Conv::_floatConvert(void) 
{
	_valueFloat = atof(_arg);
	_valueChar = static_cast<char>(_valueFloat);
	_valueInt = static_cast<int>(_valueFloat);
	_valueDouble = static_cast<double>(_valueFloat);
}

void	Conv::_doubleConvert(void) 
{
	_valueDouble = strtod(_arg, NULL);
	_valueChar = static_cast<char>(_valueDouble);
	_valueInt = static_cast<int>(_valueDouble);
	_valueFloat = static_cast<float>(_valueDouble);
}

void	Conv::_pseudoLiteralConvert(void) 
{
	std::string  pseudoLit = _arg;
	if (pseudoLit == "-inff" || pseudoLit == "+inff" || pseudoLit == "nanf")
	{
		pseudoLit = _arg;
		int i = 0;
		while (pseudoLit[i + 1])
			i++;
		pseudoLit[i] = '\0';
		_valuePseudoLiteral =  pseudoLit;
	}
	else
		_valuePseudoLiteral = _arg;
}

void Conv::_printValues(void)
{
	if (_type == PSEUDO_LITERAL)
		_printPseudoLiteral();
	else {
		_printChar();
		_printInt();
		_printFloat();
		_printDouble();
	}
}

void Conv::_printPseudoLiteral(void)
{
	std::cout
		<< "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: " << _valuePseudoLiteral << "f" << std::endl
		<< "double: " << _valuePseudoLiteral << std::endl;
}

void Conv::_printChar(void)
{
	if ((_valueInt >= 0 && _valueInt < 33) || _valueInt == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (_charLimit == true)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: '" << _valueChar << "'" << std::endl;
}

void Conv::_printInt(void)
{
	if (_intLimit || _floatLimit || _doubleLimit)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << _valueInt << std::endl;;
}

void Conv::_printFloat(void) {
	if ((_intLimit && _type == INT) ||
		_floatLimit || _doubleLimit)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << _valueFloat << "f" << std::endl;;
}

void Conv::_printDouble(void) {
	if ((_intLimit && _type == INT) ||
		(_floatLimit && _type == FLOAT) ||
		_doubleLimit)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << _valueDouble << std::endl;;
}
