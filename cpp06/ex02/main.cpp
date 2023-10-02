#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.h"
#include "B.h"
#include "C.h"

typedef enum Type {
	TYPE_A,
	TYPE_B,
	TYPE_C,
	TYPE_ERROR
}	Type;

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

static Type	g_typePtr;
static Type	g_typeRef;

int	main() {
	std::srand(std::time(NULL));
	
	Base* base = generate();

	identify(base);
	identify(*base);

	if (g_typePtr == TYPE_ERROR)
		std::cerr << "Error: g_typePtr == TYPE_ERROR" << std::endl;
	if (g_typeRef == TYPE_ERROR)
		std::cerr << "Error: g_typeRef == TYPE_ERROR" << std::endl;
	if (g_typePtr != g_typeRef)
		std::cerr << "Error: g_typePtr != g_typeRef" << std::endl;
}

Base*	generate(void) {
	const int	type = std::rand() % 3;

	if (type == TYPE_A)
		return new A();
	if (type == TYPE_B)
		return new B();
	return new C();
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "Base* p type is A*" << std::endl;
		g_typePtr = TYPE_A;
		return ;
	}
	if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "Base* p type is B*" << std::endl;
		g_typePtr = TYPE_B;
		return ;
	}
	if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "Base* p type is C*" << std::endl;
		g_typePtr = TYPE_C;
		return ;
	}
	std::cerr << "Error: type was recognized" << std::endl;
	g_typePtr = TYPE_ERROR;
}

void	identify(Base& p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "Base& p type is A&" << std::endl;
		g_typeRef = TYPE_A;
		return;
	} catch (std::exception& e) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << "Base& p type is B&" << std::endl;
		g_typeRef = TYPE_B;
		return;
	} catch (std::exception& e) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << "Base& p type is C&" << std::endl;
		g_typeRef = TYPE_C;
		return;
	} catch (std::exception& e) {}
	std::cerr << "Error: type was recognized" << std::endl;
	g_typeRef = TYPE_ERROR;
}
