#ifndef BRAIN_H
# define BRAIN_H

#include <string>

typedef unsigned char IdeasSizeUInt;

class Brain {
public:
	static const IdeasSizeUInt	ideasSize = 100;

	Brain();
	Brain(const Brain& other);

	~Brain();

	Brain&	operator=(const Brain& other);

	void				addIdea(const std::string& idea);
	const std::string&	getIdea(const IdeasSizeUInt index) const;

private:
	std::string					_ideas[Brain::ideasSize];
	IdeasSizeUInt				_ideasIndex;
};

#endif
