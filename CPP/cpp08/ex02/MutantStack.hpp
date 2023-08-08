
#pragma once
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>();
		MutantStack<T>(MutantStack const & src);
		MutantStack&	operator=(MutantStack const & rhs);
		~MutantStack();
		typedef typename std::stack<T>::container_type::iterator	iterator;
		iterator	begin();
		iterator	end();
};

#include "MutantStack.tpp"