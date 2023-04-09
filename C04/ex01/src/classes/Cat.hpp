#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include <cstdio>
# include <stdlib.h>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat &operator=(const Cat &rhs);
		void makeSound(void);
	
	private :
		Brain *_brain;
};

#endif