/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:39:49 by mverger           #+#    #+#             */
/*   Updated: 2023/05/06 17:06:16 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "classes/Bureaucrat.hpp"

int main(void) {

	try {
        Bureaucrat slave("Slave", 150);

        std::cout << slave << std::endl;

        //slave.incrementGrade();
        slave.decrementGrade();
    } 
	catch (Bureaucrat::GradeTooLowException &e) {
       std::cout << e.what() << std::endl;
    }
	return 0;
}