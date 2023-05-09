/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:45:21 by mverger           #+#    #+#             */
/*   Updated: 2023/05/09 16:47:29 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
# include <fstream>
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("ShrubberyCreationForm", 145, 137, target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy) : Form(cpy) {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	Form::operator=(rhs);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::action(Bureaucrat const &executer) const {
	Form::execute(executer);
	std::string target = getTarget() + "_shrubbery";
	std::ofstream file(target.c_str());

	if (file.is_open() == false)
		throw std::ofstream::failure("Could not open file " + getTarget() + "_shrubbery");
	file << TREE_ASCII;
}

Form *ShrubberyCreationForm::create(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}