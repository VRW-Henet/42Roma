#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int					_fix;
	static const int	_fract = 8;
public:
	Fixed();
	Fixed(const Fixed & ref);
	~Fixed();

	Fixed &operator=(const Fixed & rhs);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream&	operator<<(std::ostream& o, Fixed const & i);

#endif