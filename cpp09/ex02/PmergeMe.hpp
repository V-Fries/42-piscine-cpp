#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

#include <vector>
#include <iostream>
#include <list>
#include <stdint.h>

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);

        ~PmergeMe();

        PmergeMe& operator=(const PmergeMe& rightValue);

        template <typename T>
        static void sort(T& container) {
            if (container.size() <= 1) return;

            typename T::iterator middle(container.begin());
            std::advance(middle, container.size() / 2);

            _divideInPairs(container, middle);

            typename T::iterator smallestEnd = container.end();
            std::advance(smallestEnd, -(container.size() % 2));
            _mergeSortPairs<T>(container.begin(), middle, middle, smallestEnd);

            T result;

            result.push_back(*middle);
            result.push_back(*container.begin());

            _binaryInsertElems(container.begin(), middle, smallestEnd, result);

            if (container.size() % 2) _binaryInsert(result, container.back());

            container = result;
        }

    private:
        template <typename T>
        static void _divideInPairs(T& container, typename T::iterator middle) {
            typename T::iterator biggestIt(container.begin());
            typename T::iterator smallestIt(middle);
            while (biggestIt != middle) {
                int min = std::min(*biggestIt, *smallestIt);
                int max = std::max(*biggestIt, *smallestIt);
                *biggestIt++ = max;
                *smallestIt++ = min;
            }
        }

        template <typename T>
        static void _mergeSortPairs(typename T::iterator biggestBegin,
                                    typename T::iterator biggestEnd,
                                    typename T::iterator smallestBegin,
                                    typename T::iterator smallestEnd) {
            if (std::distance(biggestBegin, biggestEnd) < 2) return;

            typename T::iterator biggestMiddle = biggestBegin;
            std::advance(biggestMiddle, std::distance(biggestBegin, biggestEnd) / 2);
            typename T::iterator smallestMiddle = smallestBegin;
            std::advance(smallestMiddle, std::distance(smallestBegin, smallestEnd) / 2);

            T biggestFirstHalf(biggestBegin, biggestMiddle);
            T biggestSecondHalf(biggestMiddle, biggestEnd);
            T smallestFirstHalf(smallestBegin, smallestMiddle);
            T smallestSecondHalf(smallestMiddle, smallestEnd);

            _mergeSortPairs<T>(biggestFirstHalf.begin(), biggestFirstHalf.end(),
                               smallestFirstHalf.begin(), smallestFirstHalf.end());
            _mergeSortPairs<T>(biggestSecondHalf.begin(), biggestSecondHalf.end(),
                               smallestSecondHalf.begin(), smallestSecondHalf.end());

            _mergeVectors(biggestBegin, smallestBegin,
                          biggestFirstHalf, biggestSecondHalf,
                          smallestFirstHalf, smallestSecondHalf);
        }

        template <typename T>
        static void _mergeVectors(typename T::iterator biggestBegin,
                                  typename T::iterator smallestBegin,
                                  const T& biggestFirstHalf,
                                  const T& biggestSecondHalf,
                                  const T& smallestFirstHalf,
                                  const T& smallestSecondHalf) {
            typename T::const_iterator biggestFirstHalfIt(biggestFirstHalf.begin());
            typename T::const_iterator biggestSecondHalfIt(biggestSecondHalf.begin());
            typename T::const_iterator smallestFirstHalfIt(smallestFirstHalf.begin());
            typename T::const_iterator smallestSecondHalfIt(smallestSecondHalf.begin());

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

        template <typename T>
        static void _binaryInsertElems(typename T::const_iterator greatests,
                                       typename T::const_iterator lowests,
                                       const typename T::const_iterator lowestsEnd,
                                       T& result) {
            ++greatests;
            int8_t loopCount = 0;
            typename T::const_iterator lowestsIt = lowests;
            while (greatests != lowests) {
                const size_t numberOfElemsToInsert(_getNumberOfElemsToInsert(loopCount++));
                const typename T::const_iterator lastInsertedLowest(lowestsIt);
                for (size_t i(numberOfElemsToInsert); i-- && greatests != lowests;) {
                    result.push_back(*greatests++);
                    lowestsIt++;
                }
                std::advance(lowestsIt, -(lowestsIt == lowestsEnd));
                for (typename T::const_iterator it(lowestsIt); it != lastInsertedLowest; --it) {
                    _binaryInsert(result, *it);
                }
            }
        }

        static size_t _getNumberOfElemsToInsert(int8_t i);

        static size_t _jacobsthalSequence(int8_t i);

        template <typename T>
        static void _binaryInsert(T& container,
                                  const typename T::value_type valueToInsert) {
            typename T::iterator insertPoint = _getBinaryInsertionPoint(valueToInsert,
                                                                        container);
            container.insert(insertPoint, valueToInsert);
        }

        template <typename T>
        static typename T::iterator _getBinaryInsertionPoint(const typename T::value_type valueToInsert,
                                                             T& container) {
            typename T::iterator low = container.begin();
            typename T::iterator high = container.end();
            --high;

            while (low != high) {
                typename T::iterator mid = low;
                std::advance(mid, std::distance(low, high) / 2);
                if (valueToInsert == *mid) {
                    return ++mid;
                }
                if (valueToInsert > *mid) {
                    _setLowToMidPlusOne<typename T::value_type>(low, mid, high);
                }
                else {
                    _setHighToMidMinusOne<typename T::value_type>(high, mid, low);
                }
            }
            if (valueToInsert > *low)
                return ++low;
            return low;
        }

        template <typename T>
        static void _setLowToMidPlusOne(typename std::vector<T>::iterator& low,
                                       typename std::vector<T>::iterator mid,
                                       typename std::vector<T>::iterator high) {
            low = std::min(mid + 1, high);
        }

        template <typename T>
        static void _setLowToMidPlusOne(typename std::list<T>::iterator& low,
                                       typename std::list<T>::iterator mid,
                                       typename std::list<T>::iterator high) {
            ++mid;
            while (low != mid && low != high) ++low;
        }

        template <typename T>
        static void _setHighToMidMinusOne(typename std::vector<T>::iterator& high,
                                        typename std::vector<T>::iterator mid,
                                        typename std::vector<T>::iterator low) {
            high = std::max(mid - 1, low);
        }

        template <typename T>
        static void _setHighToMidMinusOne(typename std::list<T>::iterator& high,
                                        typename std::list<T>::iterator mid,
                                        typename std::list<T>::iterator low) {
            --mid;
            while (high != mid && high != low) --high;
        }
};

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vector);

#endif
