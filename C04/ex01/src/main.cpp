/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:58:45 by mverger           #+#    #+#             */
/*   Updated: 2023/03/22 15:24:51 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "classes/Cat.hpp"
# include "classes/Animal.hpp"
# include "classes/Brain.hpp"
# include "classes/Dog.hpp"
# include "classes/WrongCat.hpp"
# include "classes/WrongAnimal.hpp"

int main( void ) {
//Avec virtual
    Animal *meta = new Animal();
    Animal *j = new Dog();
    Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete j;
    delete i;
    delete meta;
    
    //Sans Virtual
    WrongAnimal *beta = new WrongAnimal();
    WrongAnimal *g = new WrongCat();
    std::cout << g->getType() << " " << std::endl;
    g->makeSound();
    beta->makeSound();
    delete g;
    delete beta;
    return 0;
}
