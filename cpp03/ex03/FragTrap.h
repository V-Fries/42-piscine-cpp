#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.h"

class FragTrap: virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string name);
	FragTrap(const FragTrap& other);
	
	~FragTrap();

	FragTrap&	operator=(const FragTrap& other);

	void	attack(const std::string& target);
	void	highFivesGuys(void);
};

#endif
