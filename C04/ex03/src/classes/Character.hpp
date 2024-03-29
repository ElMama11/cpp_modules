#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	public :
		Character();
		Character(std::string name);
		Character(const Character &cpy);
		~Character();
		Character &operator=(const Character &cpy);

		std::string const	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
				
	private :
		AMateria	*_inventory[4];
		std::string	_name;
};

#endif