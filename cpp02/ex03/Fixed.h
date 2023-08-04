#ifndef CPP02_FIXED_H
#define CPP02_FIXED_H

#include <iostream>

class Fixed {
private:
	int					_value;
	static const int	_fractional_bits = 8;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int nb);
	Fixed(const float nb);

	~Fixed();

	Fixed&	operator=(const Fixed& other);

	int		getRawBits() const;
	void	setRawBits(const int raw);

	float			toFloat(void) const;
	int				toInt(void) const;

	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);

	bool	operator>(const Fixed& fixed) const;
	bool	operator<(const Fixed& fixed) const;
	bool	operator>=(const Fixed& fixed) const;
	bool	operator<=(const Fixed& fixed) const;
	bool	operator==(const Fixed& fixed) const;
	bool	operator!=(const Fixed& fixed) const;

	Fixed	operator+(const Fixed& fixed) const;
	Fixed	operator-(const Fixed& fixed) const;
	Fixed	operator*(const Fixed& fixed) const;
	Fixed	operator/(const Fixed& fixed) const;

	void	operator+=(const Fixed& right);
	void	operator-=(const Fixed& right);
	void	operator*=(const Fixed& right);
	void	operator/=(const Fixed& right);

	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif //CPP02_FIXED_H
