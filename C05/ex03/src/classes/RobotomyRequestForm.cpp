/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:45:34 by mverger           #+#    #+#             */
/*   Updated: 2023/05/09 16:47:12 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form("RobotomyRequestForm", 72, 45, target) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy) : Form(cpy) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	this->Form::operator=(rhs);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::action(Bureaucrat const &executor) const {
	Form::execute(executor);
	std::cout << "\a";

	if (std::rand() % 2 == 0)
		std::cout << getTarget() << " is a robot!\n";
	else
		std::cout << getTarget() << " has failed\n";
}

Form *RobotomyRequestForm::create(std::string const &target)
{
	return new RobotomyRequestForm(target);
}