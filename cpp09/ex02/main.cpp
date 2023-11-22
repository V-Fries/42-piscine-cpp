#include "PmergeMe.hpp"

#include <cerrno>
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <stdexcept>
#include <limits>
#include <algorithm>

static void addNumber(std::vector<int>& vector, const std::string& numberStr);

int main(int argc, char** argv) {
    std::vector<int> vector;

    std::srand(time(NULL)); // TODO remove me
    static_cast<void>(argc);
    static_cast<void>(argv);
    static_cast<void>(addNumber);

//    while (true) {
        size_t limit = rand() % 42;
//        size_t limit = 2;
        for (size_t i = 0; i < limit; i++) {
            vector.push_back(rand() % 300);
        }
        std::vector<int> vectorSortedBySTL(vector);
        std::sort(vectorSortedBySTL.begin(), vectorSortedBySTL.end());

    //    for (int i = 1; i < argc; i++) {
    //        try {
    //            addNumber(vector, argv[i]);
    //        } catch (const std::exception& e) {
    //            std::cerr << "Error: " << e.what() << std::endl;
    //            return 1;
    //        }
    //    }

        std::list<int> list(vector.begin(), vector.end());
        std::list<int> listSortedBySTL(vector.begin(), vector.end());
        listSortedBySTL.sort();

        std::cout << "list before sort:\t" << list << std::endl;
        PmergeMe::sort(list);
        std::cout << "list post sort:\t\t" << list << std::endl;
        bool isFucked = false;
        for (size_t i(0); i < list.size(); ++i) {
            std::list<int>::iterator listIt = list.begin();
            std::list<int>::iterator listSortedBySTLIt = listSortedBySTL.begin();
            std::advance(listIt, i);
            std::advance(listSortedBySTLIt, i);
            if (*listIt != *listSortedBySTLIt) {
                isFucked = true;
                std::cout << "List fuck" << std::endl;
                break;
            }
        }
        if (!isFucked) std::cout << "List OK\n" << std::endl;

        std::cout << "vector before sort:\t" << vector << std::endl;
        PmergeMe::sort(vector);
        std::cout << "vector post sort:\t" << vector << std::endl;
        for (size_t i(0); i < vector.size(); ++i) {
            if (vector[i] != vectorSortedBySTL[i]) {
                std::cout << "Vector fuck" << std::endl;
                return 1;
            }
        }
        std::cout << "Vector OK" << std::endl;
//    }

//  TODO
//  On the first line you must display an explicit text followed by the unsorted positive
//  integer sequence.
//  • On the second line you must display an explicit text followed by the sorted positive
//  integer sequence.
//  • On the third line you must display an explicit text indicating the time used by
//  your algorithm by specifying the first container used to sort the positive integer
//  sequence.
//  • On the last line you must display an explicit text indicating the time used by
//  your algorithm by specifying the second container used to sort the positive integer
//  sequence.
}

static void addNumber(std::vector<int>& vector, const std::string& numberStr) {
    char* endPtr;
    const long number = std::strtol(numberStr.c_str(), &endPtr, 10);

    if (*endPtr != '\0')
        throw (std::invalid_argument("Argument \"" + numberStr + "\" is not a number"));
    if (errno != 0 || number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
        throw (std::invalid_argument("Argument \"" + numberStr + "\" does not fit in an int"));
    vector.push_back(static_cast<int>(number));
}
