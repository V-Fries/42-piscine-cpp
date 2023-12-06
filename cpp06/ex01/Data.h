#ifndef DATA_H
# define DATA_H

#include <iostream>

typedef struct Data {
	float	x;
	float	y;
	float	z;
}	Data;

std::ostream&	operator<<(std::ostream& os, const Data& data);

#endif