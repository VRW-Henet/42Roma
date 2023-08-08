
#ifndef ARRAY_H
#define ARRAY_H

template <class T>
class Array
{
private:
	T				*_arr;
	unsigned int	_size;
public:
	Array(): _arr(new T(0)), _size(0){};
	Array(unsigned int n): _arr(new T[n]()), _size(n){};
	Array(const Array& arr) { *this = arr; };
	~Array() { delete this->_arr; };
	Array& operator =(const Array& rhs)
	{
		if (this == &rhs)
			return (*this);
		this->_size = rhs._size;
		this->_arr = new T[this->_size]();
		for (size_t i = 0; i < this->_size; i++)
			this->_arr[i] = rhs._arr[i];
		return (*this);
	};
	T& operator[](unsigned int n)
	{
		if (n > this->_size)
			throw Array::OutofBounds();
		return (this->_arr[n]);
	};
	const T& operator[](unsigned int n) const
	{
		if (n > this->_size)
			throw Array::OutofBounds();
		return (this->_arr[n]);
	};
	unsigned int size() const { return (this->_size); };
	class OutofBounds: public std::exception
	{
		virtual const char * what() const throw()
		{
			return ("ARRAYEXCEPTION: The Index is Out of Bounds");
		}
	};
};


#endif