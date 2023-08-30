#include "ScavTrap.h"
#include "FragTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string _name;

public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap(const std::string &name);

	~DiamondTrap();

	DiamondTrap&	operator=(const DiamondTrap& other);

	using ScavTrap::attack;
	void whoAmI();
};
