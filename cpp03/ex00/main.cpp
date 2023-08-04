#include <iostream>
#include <limits>

#include "ClapTrap.h"

int	main(void)
{
	ClapTrap	clap = ClapTrap("Clap");
	ClapTrap	trap = ClapTrap("Trap");

	clap.attack("Trap");
	trap.beRepaired(2);
	trap.takeDamage(12);

	// Can't attack because he is dead
	trap.attack("Clap");
	clap.beRepaired(std::numeric_limits<unsigned int>::max());
	clap.takeDamage(100);
	clap.takeDamage(std::numeric_limits<unsigned int>::max());
	clap = ClapTrap("Clap");
	for (int i = 0; i < 12; i++)
		clap.attack("Bidule");
	trap = ClapTrap(clap);
	trap.takeDamage(100);
	clap = trap;
	trap.takeDamage(100);
	return (0);
}