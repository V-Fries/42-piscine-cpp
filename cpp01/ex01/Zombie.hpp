#include <string>

class Zombie {
public:
	Zombie();
	Zombie(const std::string& name);

	Zombie& operator=(const Zombie& other);

	void announce();

private:
	std::string name;
};

Zombie* zombieHorde(int N, std::string name);
