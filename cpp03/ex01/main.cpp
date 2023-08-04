#include <iostream>
#include <limits>

#include "ScavTrap.h"

int	main(void)
{
	{
		ClapTrap	clap("Clap");
		ClapTrap	trap("Trap");

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
	}
	{
		ScavTrap	clap("Scav");
		ScavTrap	trap("Trap");

		clap.attack("Trap");
		trap.beRepaired(2);
		trap.takeDamage(112);

		// Can't attack because he is dead
		trap.attack("Scav");
		clap.beRepaired(std::numeric_limits<unsigned int>::max());
		clap.takeDamage(100);
		clap.takeDamage(std::numeric_limits<unsigned int>::max());
		clap = ScavTrap("Scav");
		for (int i = 0; i < 52; i++)
			clap.attack("Bidule");
		trap = ScavTrap(clap);
		trap.takeDamage(100);
		clap = trap;
		trap.takeDamage(100);
	}
	{
		ClapTrap*	test = new ScavTrap("test");
		test->attack("target");
		delete test;
	}
	return (0);
}
