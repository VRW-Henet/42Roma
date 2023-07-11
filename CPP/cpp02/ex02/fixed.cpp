
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_n = 0;
}

Fixed::Fixed(int const n)
{
	this->_n = n;
	this->_n <<= this->_nbits;
}

Fixed::Fixed(float const f)
{
	this->_n = (int)(roundf(f * (1 << this->_nbits)));
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed::~Fixed(void)
{
}

Fixed&	Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->_n = rhs._n;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_n);
}

void	Fixed::setRawBits(int const raw)
{
	this->_n = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float) this->_n / (float)(1 << this->_nbits));
}

int	Fixed::toInt(void) const
{
	return (this->_n >> this->_nbits);
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator>(Fixed const & rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed	Fixed::operator+(Fixed const & rhs)
{
	Fixed	next(*this);

	next.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (next);
}

Fixed	Fixed::operator-(Fixed const & rhs)
{
	Fixed	next(*this);

	next.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (next);
}

Fixed	Fixed::operator*(Fixed const & rhs)
{
	Fixed	next(*this);
	long	f;
	long	s;

	f = (long)this->getRawBits();
	s = (long)rhs.getRawBits();
	next.setRawBits((f * s) / (1 << Fixed::_nbits));
	return (next);
}

Fixed	Fixed::operator/(Fixed const & rhs)
{
	Fixed	next(*this);

	next.setRawBits(this->getRawBits() / rhs.getRawBits());
	return (next);
}

Fixed	Fixed::operator++(void)
{
	this->_n++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	operator++();
	return (tmp);
}

Fixed	Fixed::operator--(void)
{
	this->_n--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	operator--();
	return (tmp);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	return (f1 > f2 ? f2 : f1);
}

Fixed const	&Fixed::min(Fixed const & f1, Fixed const & f2)
{
	return (f1 > f2 ? f2 : f1);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	return (f1 < f2 ? f2 : f1);
}

Fixed const	&Fixed::max(Fixed const & f1, Fixed const & f2)
{
	return (f1 < f2 ? f2 : f1);
}

std::ostream&	operator<<(std::ostream& o, Fixed const & i)
{
	o << i.toFloat();
	return (o);
}