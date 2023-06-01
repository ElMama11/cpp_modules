/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:39:06 by mverger           #+#    #+#             */
/*   Updated: 2023/06/01 18:22:56 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _result(0) {
}

RPN::RPN(const RPN& cpy) {
	*this = cpy;
}

RPN& RPN::operator=(const RPN &rhs) {
	if (this != &rhs) {
		this->_stack = rhs._stack;
		this->_result = rhs._result;
	}
	return *this;
}

RPN::~RPN() {
}

void	RPN::process(const std::string &expr) {
	std::string token;

	for (size_t i = 0; i < expr.length(); i++)
	{
		char c = expr[i];
		if (c == ' ')
			continue;
		else if (isdigit(c))
			token = token + c;
		else if (isOperator(c))
		{
			if (_stack.size() < 2)
				throw insufficientOperands();
			int num2 = _stack.top();
			_stack.pop();
			int num1 = _stack.top();
			_stack.pop();
			calculate(num1, num2, c);
		}
		else
			throw invalidToken();
		if (!token.empty())
		{
			_stack.push(atoi(token.c_str()));
			token.clear();
		}
	}
	if (_stack.size() != 1)
		throw tooManyOperands();
	_result = _stack.top();
	_stack.pop();
}

bool	RPN::isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

void	RPN::calculate(int num1, int num2, char op) {
	switch (op)
	{
		case '+':
			_stack.push(num1 + num2);
			break;
		case '-':
			_stack.push(num1 - num2);
			break;
		case '*':
			_stack.push(num1 * num2);
			break;
		case '/':
			if (num2 == 0)
				throw divisionByZero();
			_stack.push(num1 / num2);
			break;
	}
}

int	RPN::getResult() {
	return (this->_result);
}

std::ostream&	operator<<(std::ostream& o, RPN &i) {
	o << i.getResult();
	return o;
}