#ifndef CPP02_FIXED_H
#define CPP02_FIXED_H

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
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed_point);

#endif //CPP02_FIXED_H
