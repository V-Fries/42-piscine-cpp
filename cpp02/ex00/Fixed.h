#ifndef CPP02_FIXED_H
#define CPP02_FIXED_H


class Fixed {
private:
	int					_value;
	static const int	_fractional_bits = 8;

public:
	Fixed();
	Fixed(Fixed& other);

	~Fixed();

	Fixed&	operator=(const Fixed& other);

	int		getRawBits() const;
	void	setRawBits(const int raw);
};

#endif //CPP02_FIXED_H
