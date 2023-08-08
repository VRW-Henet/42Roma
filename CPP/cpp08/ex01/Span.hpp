#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

class Span
{
	private:
	std::list<int> _list;
		unsigned int _N;

	public:
		Span();
        Span(unsigned int N);
        virtual ~Span();
        Span& operator=(const Span &rhs);

		void						addNumber(int n);
		void						addIter(const std::list<int>::iterator &start, const std::list<int>::iterator &end);
		int							shortestSpan();
		int 						longestSpan();
		const std::list< int >*		getList( void ) const;

};
std::ostream& operator<<( std::ostream&, const Span& );

#endif