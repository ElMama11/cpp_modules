#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void Announce(void);

	private:
		std::string	_name;
};
#endif

Zombie* newZombie(std::string name);
void    randomChump(std::string name);