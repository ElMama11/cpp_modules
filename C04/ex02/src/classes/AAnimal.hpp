#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"
#include <cstdio>
#include <cstdlib>

class AAnimal
{
protected:
		std::string _type;
		AAnimal();

	public:
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal();
		AAnimal &operator=(const AAnimal &rhs);
		virtual void makeSound(void)const = 0;
		std::string getType(void)const;

};

#endif