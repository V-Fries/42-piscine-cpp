#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.h"

class ScavTrap: virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap& other);
	
	~ScavTrap();

	ScavTrap&	operator=(const ScavTrap& other);

	void	attack(const std::string& target);
	void	guardGate(void);
};

#endif
