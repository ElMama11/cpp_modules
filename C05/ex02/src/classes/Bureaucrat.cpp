/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:27:01 by mverger           #+#    #+#             */
/*   Updated: 2023/06/02 16:05:38 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name), _grade(cpy._grade) {
	*this = cpy;
}

Bureaucrat::~Bureaucrat() {
}

/* Operator overload*/

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs)
	{
		_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat &rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}

/* Public ft */

std::string	Bureaucrat::getName(void) const {
	return _name;
}

int Bureaucrat::getGrade(void) const {
	return _grade;
}

void Bureaucrat::incrementGrade(void) {
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade(void) {
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form &form) {
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
	
}

void Bureaucrat::executeForm(Form const &form) {
	try
	{
		form.action(*this);
		std::cout << *this << " executes " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << *this << " cannot execute " <<  form.getName()<< " because " << e.what() << std::endl;
	}
}