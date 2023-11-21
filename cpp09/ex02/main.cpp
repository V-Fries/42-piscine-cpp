#include "PmergeMe.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <stdexcept>
#include <limits>

 static void	addNumber(std::vector<int>& vector, const std::string& numberStr);
// static std::ostream&	operator<<(std::ostream& os, const std::list<int>& list);

int	main(int argc, char **argv) {

	std::srand(time(NULL));

    std::vector<int> vector;

    for (int i = 1; i < argc; i++) {
        try {
            addNumber(vector, argv[i]);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }
    }

    //std::list<int>	list(vector.begin(), vector.end());

    std::cout << "vector before sort:\t" << vector << std::endl;
    PmergeMe::sortVector(vector);
    std::cout << "vector post sort:\t" << vector << std::endl;

    int	i = std::numeric_limits<int>::min();
    for (std::vector<int>::const_iterator it = vector.begin(); it != vector.end(); ++it) {
        if (*it < i) {
            std::cout << "Fuck sortVector" << std::endl;
            return 1;
        }
        i = *it;
    }
    std::cout << "OK" << std::endl;

//	 std::cout << "list before sort:\t" << list << std::endl;
//	 //sort
//	 std::cout << "list post sort:\t" << list << std::endl;

//	 TODO
//	 On the first line you must display an explicit text followed by the unsorted positive
//	 integer sequence.
//	 • On the second line you must display an explicit text followed by the sorted positive
//	 integer sequence.
//	 • On the third line you must display an explicit text indicating the time used by
//	 your algorithm by specifying the first container used to sort the positive integer
//	 sequence.
//	 • On the last line you must display an explicit text indicating the time used by
//	 your algorithm by specifying the second container used to sort the positive integer
//	 sequence.
}

 static void	addNumber(std::vector<int>& vector, const std::string& numberStr) {
 	char*		endPtr;
 	const long	number = std::strtol(numberStr.c_str(), &endPtr, 10);

 	if (*endPtr != '\0')
 		throw (std::invalid_argument("Argument \"" + numberStr + "\" is not a number"));
 	if (errno != 0 || number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
 		throw (std::invalid_argument("Argument \"" + numberStr + "\" does not fit in an int"));
 	vector.push_back(static_cast<int>(number));
 }

// static std::ostream&	operator<<(std::ostream& os, const std::list<int>& list) {
// 	std::list<int>::const_iterator	it = list.begin();
// 	std::list<int>::const_iterator	lastElem = list.end();
// 	--lastElem;
//
// 	if (it == list.end())
// 		return os;
// 	for (; it != lastElem; it++) {
// 		std::cout << *it << ", ";
// 	}
// 	std::cout << *it;
// 	return os;
// }
