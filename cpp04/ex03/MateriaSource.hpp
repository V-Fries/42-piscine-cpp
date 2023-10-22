#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
private:
	static const int	_inventorySize = 4;

	AMateria*	_inventory[_inventorySize];

public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);

	~MateriaSource();

	MateriaSource&	operator=(const MateriaSource& rightValue);

	void		learnMateria(AMateria* m);
	AMateria*	createMateria(const std::string& type);
};
