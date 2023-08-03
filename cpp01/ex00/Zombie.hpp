#include <string>

class Zombie {
public:
	Zombie(const std::string& name);

	void announce();

private:
	std::string name;
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);
