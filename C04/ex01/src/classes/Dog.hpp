#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include <cstdio>
# include <stdlib.h>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();
		Dog &operator=(const Dog &rhs);
		void makeSound(void);
		
	private :
		Brain *_brain;
};

#endif