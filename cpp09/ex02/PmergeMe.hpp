#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

#include <vector>
#include <iostream>
#include <cstdint>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);

        ~PmergeMe();

        PmergeMe& operator=(const PmergeMe& rightValue);

        static void	sortVector(std::vector<int>& vector);

    private:
        static void _divideInPairs(std::vector<int>& vector,
                                   std::vector<int>::iterator middle);

        static void _mergeSortPairs(std::vector<int>::iterator biggestBegin,
                                    std::vector<int>::iterator biggestEnd,
                                    std::vector<int>::iterator smallestBegin,
                                    std::vector<int>::iterator smallestEnd);

        static void _mergeVectors(std::vector<int>::iterator biggestBegin,
                                  std::vector<int>::iterator smallestBegin,
                                  const std::vector<int>& biggestFirstHalf,
                                  const std::vector<int>& biggestSecondHalf,
                                  const std::vector<int>& smallestFirstHalf,
                                  const std::vector<int>& smallestSecondHalf);


        static void _binaryInsertElems(const std::vector<int>& vector,
                                       std::vector<int>& result,
                                       std::vector<int>::const_iterator middle);

        static size_t _jacobsthalSequence(int8_t i);

        static void _binaryInsert(std::vector<int>& vector,
                                  int valueToInsert);

        static std::vector<int>::iterator _getBinaryInsertionPoint(int valueToInsert,
                                                                   std::vector<int>::iterator begin,
                                                                   std::vector<int>::iterator end);
};

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vector);

#endif
