#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {

	public:
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal();
		Animal &operator=(const Animal &rhs);
		virtual void makeSound(void);
		std::string getType(void);

	protected:
		std::string type;

};

#endif