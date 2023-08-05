#include <iostream>

#include "Point.h"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	//	Test 1 inside square triangle
	{
		Point	a = Point(0.f, 0.f);
		Point	b = Point(2.5f, 0.f);
		Point	c = Point(0.f, 2.f);
		Point	p = Point(1.f, 0.4f);

		if (bsp(a, b, c, p))
			std::cout << "Test 1: OK" << std::endl;
		else
			std::cerr << "Test 1: KO" << std::endl;
	}
	//	Test 2 outside square triangle
	{
		Point	a = Point(0.f, 0.f);
		Point	b = Point(2.5f, 0.f);
		Point	c = Point(0.f, 2.f);
		Point	p = Point(-1.f, 0.4f);

		if (!bsp(a, b, c, p))
			std::cout << "Test 2: OK" << std::endl;
		else
			std::cerr << "Test 2: KO" << std::endl;
	}
	//	Test 3 on vertex of square rectangle
	{
		Point	a = Point(0.f, 0.f);
		Point	b = Point(2.5f, 0.f);
		Point	c = Point(0.f, 2.f);
		Point	p = Point(a);

		if (!bsp(a, b, c, p))
			std::cout << "Test 3: OK" << std::endl;
		else
			std::cerr << "Test 3: KO" << std::endl;
	}
	//	Test 4 outside non square rectangle
	{
		Point	a = Point(-31.06407f,-4.85091f);
		Point	b = Point(-16.79f, 0.f);
		Point	c = Point(0.f, -25.f);
		Point	p = Point(-11.44253f,-6.84952f);

		if (!bsp(a, b, c, p))
			std::cout << "Test 4: OK" << std::endl;
		else
			std::cerr << "Test 4: KO" << std::endl;
	}
	//	Test 5 inside non square rectangle
	{
		Point	a = Point(-31.06407f,-4.85091f);
		Point	b = Point(-16.79f, 0.f);
		Point	c = Point(0.f, -25.f);
		Point	p = Point(-17.62755f,-1.23542f);

		if (bsp(a, b, c, p))
			std::cout << "Test 5: OK" << std::endl;
		else
			std::cerr << "Test 5: KO" << std::endl;
	}
	//	Test 6 on vertex of non square rectangle
	{
		Point	a = Point(-31.06407f,-4.85091f);
		Point	b = Point(-16.79f, 0.f);
		Point	c = Point(0.f, -25.f);
		Point	p = Point(c);

		if (!bsp(a, b, c, p))
			std::cout << "Test 6: OK" << std::endl;
		else
			std::cerr << "Test 6: KO" << std::endl;
	}
	return (0);
}
