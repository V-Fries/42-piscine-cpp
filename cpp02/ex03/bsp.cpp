#include "Point.h"

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed t_ab = point.getX() * (c.getY() - a.getY())
					- a.getX() * (c.getY() - a.getY())
					- (point.getY() - a.getY()) * (c.getX() - a.getX());
	t_ab = t_ab / ((b.getX() - a.getX()) * (c.getY() - a.getY())
					- (b.getY() - a.getY()) * (c.getX() - a.getX()));
	
	if (t_ab <= 0)
		return false;

	Fixed t_ac = point.getY() - a.getY() - t_ab * (b.getY() - a.getY());
	t_ac = t_ac / (c.getY() - a.getY());

	return (t_ac > 0 && t_ab + t_ac < 1);
}
