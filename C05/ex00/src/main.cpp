/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:39:49 by mverger           #+#    #+#             */
/*   Updated: 2023/05/08 16:04:47 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "classes/Bureaucrat.hpp"

int main(void) {

	Bureaucrat slave("Slave", 150);
	
	try {
        std::cout << slave << std::endl;
        slave.decrementGrade();
    } 
	catch (Bureaucrat::GradeTooLowException &e) {
       std::cout << e.what() << std::endl;
    }
	
	Bureaucrat slave2("Jeandroitos", 1);
	
	try {
        std::cout << slave2 << std::endl;
		slave2.incrementGrade();
    } 
	catch (Bureaucrat::GradeTooHighException &e) {
       std::cout << e.what() << std::endl;
    }
	return 0;
}