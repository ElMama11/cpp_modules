/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:58:45 by mverger           #+#    #+#             */
/*   Updated: 2023/03/23 15:54:31 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "classes/Cat.hpp"
# include "classes/Animal.hpp"
# include "classes/Brain.hpp"
# include "classes/Dog.hpp"
# include "classes/WrongCat.hpp"
# include "classes/WrongAnimal.hpp"

int main( void ) {
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();

    // delete j;//should not create a leak
    // delete i;

    const Animal *animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
    for (int i = 0; i < 4; i++)
        delete animals[i];

    return 0;
}
