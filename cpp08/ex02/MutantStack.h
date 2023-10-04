#pragma once

#include <stack>

template <typename T, typename Deque = std::deque<T> >
class MutantStack : public std::stack<T> {
public:
	typedef typename Deque::iterator				iterator;
	typedef typename Deque::const_iterator			const_iterator;
	typedef typename Deque::reverse_iterator		reverse_iterator;
	typedef typename Deque::const_reverse_iterator	const_reverse_iterator;


	iterator		begin() throw() {
		return this->c.begin();
	}

	const_iterator	begin() const throw() {
		return this->c.begin();
	}

	iterator		end() throw() {
		return this->c.end();
	}
	
	const_iterator	end() const throw() {
		return this->c.end();
	}
	

	reverse_iterator		rbegin() throw() {
		return this->c.rbegin();
	}

	const_reverse_iterator	rbegin() const throw() {
		return this->c.rbegin();
	}

	reverse_iterator		rend() throw() {
		return this->c.rend();
	}

	const_reverse_iterator	rend() const throw() {
		return this->c.rend();
	}
};
