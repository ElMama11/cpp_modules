/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:39:49 by mverger           #+#    #+#             */
/*   Updated: 2023/06/03 13:47:45 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/Span.hpp"

int main( void ) {
	
	Span sp = Span(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
				
		std::cout << "shortest : " << sp.shortestSpan() << std::endl;
		std::cout << "longest : " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::list<int>::iterator ite;
	
	try {
        std::list<int>    l( 10 );
        std::srand( time ( NULL ) );
        std::generate( l.begin(), l.end(), std::rand );

        Span span( l.size() );
        span.addNumbers( l.begin(), l.end() );
		
		for(ite = l.begin(); ite != l.end(); ite++)
			 std::cout << *ite << std::endl;
		
		std::cout << "shortest : " << span.shortestSpan() << std::endl;
		std::cout << "longest : " << span.longestSpan() << std::endl;
        
    } catch ( std::exception& e ) {
        std::cout << e.what() << std::endl; 
    }
	return 0;
}