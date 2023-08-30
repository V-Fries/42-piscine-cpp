#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>

class ClapTrap {
protected:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
public:
	ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap(const std::string& name);

	virtual ~ClapTrap();

	ClapTrap&	operator=(const ClapTrap& other);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
