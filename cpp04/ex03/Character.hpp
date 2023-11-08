#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
private:
	static const int _inventorySize = 4;

	std::string	_name;
	AMateria*	_inventory[_inventorySize];
	bool		_isEquipped[_inventorySize];

	bool	isIndexValid(int idx) const;

public:
	Character();
	Character(const Character& other);
	Character(const std::string& name);

	~Character();

	Character&	operator=(const Character& rightValue);

	const std::string&	getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
};

#endif
