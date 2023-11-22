#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { static_cast<void>(other); }

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& rightValue) {
    static_cast<void>(rightValue);
    return *this;
}

size_t PmergeMe::_getNumberOfElemsToInsert(const int8_t i) {
    return (_jacobsthalSequence(i + 3) - _jacobsthalSequence(i + 2));
}

size_t PmergeMe::_jacobsthalSequence(const int8_t i) {
    static size_t cache[65] = {0, 1};

    if (i <= 0) return 0;
    if (i >= 65) return 12297829382473034411u;
    if (cache[i] != 0) return cache[i];

    cache[i] = _jacobsthalSequence(i - 1) + 2 * _jacobsthalSequence(i - 2);
    return cache[i];
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vector) {
    std::vector<int>::const_iterator it = vector.begin();
    std::vector<int>::const_iterator lastElem = vector.end() - 1;

    if (it == vector.end())
        return os;
    for (; it != lastElem; it++) {
        os << *it << ", ";
    }
    os << *it;
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::list<int>& list) {
    std::list<int>::const_iterator it = list.begin();
    std::list<int>::const_iterator lastElem = list.end();
    std::advance(lastElem, -1);

    if (it == list.end())
        return os;
    for (; it != lastElem; it++) {
        os << *it << ", ";
    }
    os << *it;
    return os;
}