#include "PmergeMe.hpp"

#include <cerrno>
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <stdexcept>
#include <limits>
#include <chrono>

typedef std::chrono::time_point<std::chrono::steady_clock> Time;

static void addNumber(std::vector<int>& vector, const std::string& numberStr);

int main(int argc, char** argv) {
    // I don't check argc as you could want to test the sorting functions with 0 elems
    std::vector<int> vector;
    try {
        for (int i = 1; i < argc; ++i) {
            addNumber(vector, argv[i]);
        }
    } catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return 2;
    }
    std::list<int> list(vector.begin(), vector.end());

    std::cout << "Unsorted numbers: " << vector << std::endl;

    Time startTime = std::chrono::high_resolution_clock::now();
    PmergeMe::sort(vector);
    Time endTime = std::chrono::high_resolution_clock::now();
    long long vectorSortDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    startTime = std::chrono::high_resolution_clock::now();
    PmergeMe::sort(list);
    endTime = std::chrono::high_resolution_clock::now();
    long long listSortDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    std::cout << "Sorted numbers: " << vector << "\n"
                 "Time to sort vector: " << vectorSortDuration << "ms\n"
                 "Time to sort list: " << listSortDuration << "ms" << std::endl;
}

static void addNumber(std::vector<int>& vector, const std::string& numberStr) {
    char* endPtr;
    const long number = std::strtol(numberStr.c_str(), &endPtr, 10);

    if (*endPtr != '\0')
        throw (std::invalid_argument("Argument \"" + numberStr + "\" is not an int"));
    if (errno != 0 || number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
        throw (std::invalid_argument("Argument \"" + numberStr + "\" does not fit in an int"));
    vector.push_back(static_cast<int>(number));
}
