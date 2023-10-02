#include "Data.h"

std::ostream&	operator<<(std::ostream& os, const Data& data) {
	os << "Data:\n\t.x == " << data.x << "\n\t.y == " << data.y << "\n\t.z == " << data.z;
	return os;
}
