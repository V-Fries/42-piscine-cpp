#include <list>
#include <iostream>

#include "MutantStack.h"

static MutantStack<int>	createStack();
static std::list<int>	createList();

static void	testIterators();
static void	testConstIterators();
static void	testReverseIterators();
static void	testConstReverseIterators();

int	main() {
	testIterators();
	std::cout << std::endl;
	testConstIterators();
	std::cout << std::endl;

	testReverseIterators();
	std::cout << std::endl;
	testConstReverseIterators();
	std::cout << std::endl;
}

static MutantStack<int>	createStack() {
	MutantStack<int>	stack;

	stack.push(543);
	stack.push(89);
	stack.pop();
	stack.push(5);
	stack.push(3);
	stack.pop();
	stack.push(77);
	stack.push(42);
	return stack;
}

static std::list<int>	createList() {
	std::list<int>	list;

	list.push_back(543);
	list.push_back(89);
	list.pop_back();
	list.push_back(5);
	list.push_back(3);
	list.pop_back();
	list.push_back(77);
	list.push_back(42);
	return list;
}

static void	testIterators() {
	std::cout << "testIterators() Stack" << std::endl;
	MutantStack<int>			stack = createStack();
	MutantStack<int>::iterator	itStack = stack.begin();
	MutantStack<int>::iterator	iteStack = stack.end();
	++itStack;
	--itStack;
	while (itStack != iteStack) {
		std::cout << *itStack << std::endl;
		++itStack;
	}
	std::stack<int>	s(stack);

	std::cout << "\ntestIterators() List" << std::endl;
	std::list<int>				list = createList();
	std::list<int>::iterator	itList = list.begin();
	std::list<int>::iterator	iteList = list.end();
	++itList;
	--itList;
	while (itList != iteList) {
		std::cout << *itList << std::endl;
		++itList;
	}
	std::list<int>	l(list);

}

static void	testConstIterators() {
	std::cout << "testConstIterators() Stack" << std::endl;
	const MutantStack<int>				stack = createStack();
	MutantStack<int>::const_iterator	itStack = stack.begin();
	MutantStack<int>::const_iterator	iteStack = stack.end();
	++itStack;
	--itStack;
	while (itStack != iteStack) {
		std::cout << *itStack << std::endl;
		++itStack;
	}
	const std::stack<int>	s(stack);

	std::cout << "\ntestConstIterators() List" << std::endl;
	const std::list<int>			list = createList();
	std::list<int>::const_iterator	itList = list.begin();
	std::list<int>::const_iterator	iteList = list.end();
	++itList;
	--itList;
	while (itList != iteList) {
		std::cout << *itList << std::endl;
		++itList;
	}
	const std::list<int>	l(list);
}

static void	testReverseIterators() {
	std::cout << "testReverseIterators() Stack" << std::endl;
	MutantStack<int>					stack = createStack();
	MutantStack<int>::reverse_iterator	itStack = stack.rbegin();
	MutantStack<int>::reverse_iterator	iteStack = stack.rend();
	++itStack;
	--itStack;
	while (itStack != iteStack) {
		std::cout << *itStack << std::endl;
		++itStack;
	}
	std::stack<int>	s(stack);

	std::cout << "\ntestReverseIterators() List" << std::endl;
	std::list<int>						list = createList();
	std::list<int>::reverse_iterator	itList = list.rbegin();
	std::list<int>::reverse_iterator	iteList = list.rend();
	++itList;
	--itList;
	while (itList != iteList) {
		std::cout << *itList << std::endl;
		++itList;
	}
	std::list<int>	l(list);

}

static void	testConstReverseIterators() {
	std::cout << "testConstReverseIterators() Stack" << std::endl;
	const MutantStack<int>						stack = createStack();
	MutantStack<int>::const_reverse_iterator	itStack = stack.rbegin();
	MutantStack<int>::const_reverse_iterator	iteStack = stack.rend();
	++itStack;
	--itStack;
	while (itStack != iteStack) {
		std::cout << *itStack << std::endl;
		++itStack;
	}
	const std::stack<int>	s(stack);

	std::cout << "\ntestConstReverseIterators() List" << std::endl;
	const std::list<int>					list = createList();
	std::list<int>::const_reverse_iterator	itList = list.rbegin();
	std::list<int>::const_reverse_iterator	iteList = list.rend();
	++itList;
	--itList;
	while (itList != iteList) {
		std::cout << *itList << std::endl;
		++itList;
	}
	const std::list<int>	l(list);
}
