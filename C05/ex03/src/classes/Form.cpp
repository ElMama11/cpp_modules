/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:15:06 by mverger           #+#    #+#             */
/*   Updated: 2023/05/09 15:38:23 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _grade_to_sign(0), _grade_to_execute(0) {
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute, std::string const target) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute), _target(target) {
	_is_signed = false;
}

Form::Form(Form const &cpy) : _name(cpy.getName()), _grade_to_sign(cpy.getGradeToSign()), _grade_to_execute(cpy.getGradeToExecute()), _target(cpy._target) {
	_is_signed = cpy._is_signed;
}

Form::~Form() {
}

/* Operator overload */

Form &Form::operator=(const Form &rhs) {
	_is_signed = rhs._is_signed;
	return *this;
}

std::ostream &operator<<(std::ostream &o, Form &rhs) {
	if (rhs.getGradeToExecute() == true)
		o << rhs.getName() << " form is SIGNED, grade to be signed is " << rhs.getGradeToSign() << " , grade to be execute is " << rhs.getGradeToExecute();
	else
		o << rhs.getName() << " form is NOT SIGNED, grade to be signed is " << rhs.getGradeToSign() << " , grade to be execute is " << rhs.getGradeToExecute();
	return o;
}

/* Public ft*/

std::string	Form::getName(void) const {
	return _name;
}

bool Form::getIsSigned(void) const {
	return _is_signed;
}

int Form::getGradeToSign(void) const {
	return _grade_to_sign;
}

int Form::getGradeToExecute(void) const {
	return _grade_to_execute;
}

std::string Form::getTarget(void) const {
	return _target;
}

void Form::beSigned(Bureaucrat bureaucrat) {
	if (_is_signed == true)
		return ;
	if (bureaucrat.getGrade() <= _grade_to_sign)
		_is_signed = true;
	else
		throw Form::GradeTooLowException();
}

void Form::execute(Bureaucrat const &executor) const {
	if (getIsSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > _grade_to_execute)
		throw GradeTooLowException();
}