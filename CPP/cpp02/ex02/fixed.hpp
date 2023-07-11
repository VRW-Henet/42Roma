
#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_n;
		static const int	_nbits = 8;
	public:
		Fixed();
		Fixed(int const n);
		Fixed(float const f);
		Fixed(Fixed const & src);
		virtual ~Fixed();
		Fixed&	operator=(Fixed const & rhs);
		bool	operator>(Fixed const & rhs) const;
		bool	operator<(Fixed const & rhs) const;
		bool	operator>=(Fixed const & rhs) const;
		bool	operator<=(Fixed const & rhs) const;
		bool	operator==(Fixed const & rhs) const;
		bool	operator!=(Fixed const & rhs) const;
		Fixed	operator+(Fixed const & rhs);
		Fixed	operator-(Fixed const & rhs);
		Fixed	operator*(Fixed const & rhs);
		Fixed	operator/(Fixed const & rhs);
		Fixed	operator++();
		Fixed	operator++(int i);
		Fixed	operator--();
		Fixed	operator--(int i);
		int						getRawBits() const;
		void					setRawBits(int const raw);
		float					toFloat(void) const;
		int						toInt(void) const;
		static Fixed&			min(Fixed& f1, Fixed& f2);
		static Fixed const &	min(Fixed const & f1, Fixed const & f2);
		static Fixed&			max(Fixed& f1, Fixed& f2);
		static Fixed const &	max(Fixed const & f1, Fixed const & f2);
};

std::ostream&	operator<<(std::ostream& o, Fixed const & i);

#endif