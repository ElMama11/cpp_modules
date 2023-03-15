/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:58:45 by mverger           #+#    #+#             */
/*   Updated: 2023/03/15 18:51:24 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "classes/Cat.hpp"
# include "classes/Animal.hpp"
# include "classes/Dog.hpp"

int main( void ) {
//Avec virtual
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete j;
    delete i;
    delete meta;
    
    //Sans Virtual
    const WrongAnimal *beta = new WrongAnimal();
    const WrongAnimal *k = new WrongDog();
    const WrongAnimal *g = new WrongCat();
    std::cout << k->getType() << " " << std::endl;
    std::cout << g->getType() << " " << std::endl;
    g->makeSound(); // will output the cat sound!
    k->makeSound();
    beta->makeSound();
    delete k;
    delete g;
    delete beta;
    return 0;
}
