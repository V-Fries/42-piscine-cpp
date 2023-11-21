#include "PmergeMe.hpp"

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vector);

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) {static_cast<void>(other);}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& rightValue) {
    static_cast<void>(rightValue);
    return *this;
}

void PmergeMe::sortVector(std::vector<int>& vector) {
    if (vector.size() <= 1) return;

    std::vector<int>::iterator middle(vector.begin() + (vector.end() - vector.begin()) / 2);

    _divideInPairs(vector, middle);

    _mergeSortPairs(vector.begin(), middle, middle, vector.end() - vector.size() % 2);

    std::vector<int> result;

    result.push_back(*middle);
    result.push_back(*vector.begin());

    _binaryInsertElems(vector, result, middle);

    if (vector.size() % 2) _binaryInsert(result, vector.end()[-1]);

    vector = result;
}

void PmergeMe::_divideInPairs(std::vector<int>& vector,
                              std::vector<int>::iterator middle) {
    std::vector<int>::iterator biggestIt(vector.begin());
    std::vector<int>::iterator smallestIt(middle);
    while (biggestIt != middle) {
        int min = std::min(*biggestIt, *smallestIt);
        int max = std::max(*biggestIt, *smallestIt);
        *biggestIt++ = max;
        *smallestIt++ = min;
    }
}

void PmergeMe::_mergeSortPairs(std::vector<int>::iterator biggestBegin,
                               std::vector<int>::iterator biggestEnd,
                               std::vector<int>::iterator smallestBegin,
                               std::vector<int>::iterator smallestEnd) {
    if (biggestEnd - biggestBegin < 2) return;

    std::vector<int>::iterator biggestMiddle = biggestBegin
                                                + (biggestEnd - biggestBegin) / 2;
    std::vector<int>::iterator smallestMiddle = smallestBegin
                                                + (smallestEnd - smallestBegin) / 2;

    std::vector<int> biggestFirstHalf(biggestBegin, biggestMiddle);
    std::vector<int> biggestSecondHalf(biggestMiddle, biggestEnd);
    std::vector<int> smallestFirstHalf(smallestBegin, smallestMiddle);
    std::vector<int> smallestSecondHalf(smallestMiddle, smallestEnd);

    _mergeSortPairs(biggestFirstHalf.begin(), biggestFirstHalf.end(),
                    smallestFirstHalf.begin(), smallestFirstHalf.end());
    _mergeSortPairs(biggestSecondHalf.begin(), biggestSecondHalf.end(),
                    smallestSecondHalf.begin(), smallestSecondHalf.end());

    _mergeVectors(biggestBegin, smallestBegin,
                  biggestFirstHalf, biggestSecondHalf,
                  smallestFirstHalf, smallestSecondHalf);

}

void PmergeMe::_mergeVectors(std::vector<int>::iterator biggestBegin,
                             std::vector<int>::iterator smallestBegin,
                             const std::vector<int>& biggestFirstHalf,
                             const std::vector<int>& biggestSecondHalf,
                             const std::vector<int>& smallestFirstHalf,
                             const std::vector<int>& smallestSecondHalf) {
    std::vector<int>::const_iterator biggestFirstHalfIt(biggestFirstHalf.begin());
    std::vector<int>::const_iterator biggestSecondHalfIt(biggestSecondHalf.begin());
    std::vector<int>::const_iterator smallestFirstHalfIt(smallestFirstHalf.begin());
    std::vector<int>::const_iterator smallestSecondHalfIt(smallestSecondHalf.begin());

    while (biggestFirstHalfIt != biggestFirstHalf.end()
           && biggestSecondHalfIt != biggestSecondHalf.end()) {
        if (*biggestFirstHalfIt < *biggestSecondHalfIt) {
            *biggestBegin++ = *biggestFirstHalfIt++;
            *smallestBegin++ = *smallestFirstHalfIt++;
        } else {
            *biggestBegin++ = *biggestSecondHalfIt++;
            *smallestBegin++ = *smallestSecondHalfIt++;
        }
    }
    while (biggestFirstHalfIt != biggestFirstHalf.end()) {
        *biggestBegin++ = *biggestFirstHalfIt++;
        *smallestBegin++ = *smallestFirstHalfIt++;
    }
    while (biggestSecondHalfIt != biggestSecondHalf.end()) {
        *biggestBegin++ = *biggestSecondHalfIt++;
        *smallestBegin++ = *smallestSecondHalfIt++;
    }
}


void PmergeMe::_binaryInsertElems(const std::vector<int>& vector,
                                  std::vector<int>& result,
                                  const std::vector<int>::const_iterator middle) {
    int8_t jacobsthalSequenceIndex = 3;
    size_t lastInsertedElem = 0;
    size_t lastElemToInsert = middle - 1 - vector.begin();
    while (lastInsertedElem < lastElemToInsert) {
        size_t elemToInsertIndex = std::min(_jacobsthalSequence(jacobsthalSequenceIndex++),
                                            vector.size() - 1);
        for (size_t i = lastInsertedElem; i <= elemToInsertIndex; ++i) {
            result.push_back(vector[i]);
        }
        for (size_t i = elemToInsertIndex; i > lastInsertedElem; --i) {
            _binaryInsert(result, middle[i]);
        }
        lastInsertedElem = elemToInsertIndex;
    }
}

size_t PmergeMe::_jacobsthalSequence(int8_t i) {
    static size_t cache[127] = {0, 1};

    if (i <= 0) return 0;
    if (cache[i] != 0) return cache[i];

    cache[i] = _jacobsthalSequence(i - 1) + 2 * _jacobsthalSequence(i - 2);
    return cache[i];
}

void PmergeMe::_binaryInsert(std::vector<int>& vector,
                             const int valueToInsert) {
    std::vector<int>::iterator insertPoint = _getBinaryInsertionPoint(valueToInsert,
                                                                      vector.begin(),
                                                                      vector.end());
    vector.insert(insertPoint, valueToInsert);
}

std::vector<int>::iterator PmergeMe::_getBinaryInsertionPoint(const int valueToInsert,
                                                              std::vector<int>::iterator begin,
                                                              std::vector<int>::iterator end) {
    std::vector<int>::iterator low = begin;
    std::vector<int>::iterator high = end - 1;

    while (high > low) {
        std::vector<int>::iterator mid = low + (high - low) / 2;
        if (valueToInsert == *mid)
            return mid + 1;
        if (valueToInsert > *mid)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (valueToInsert > *low)
        return low + 1;
    return low;
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
