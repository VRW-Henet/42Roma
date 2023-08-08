#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T>
void	swap(T &arg1, T &arg2){
	T tmp;
	tmp = arg1;
	arg1 = arg2;
	arg2 = tmp;
}

template <typename T>
T	min(T &arg1, T &arg2)
{
	return (arg1 < arg2 ? arg1 : arg2);
}

template <typename T>
T max(T &arg1, T &arg2)
{
	return (arg1 > arg2 ? arg1 : arg2);
}

template <typename T>
void iter(T* addr, int size, void (*f)(const T&))
{
    for (int i = 0; i <size; i++)
        (*f)(addr[i]);
}

template <typename T>
void temprint(const T& p)
{
    std::cout << p << std::endl;
}
#endif