#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>

class Converter
{
	public:
		Converter();
        Converter(const Converter &rhs);
        virtual ~Converter();
        Converter& operator=(const Converter &rhs);

		void convert(const std::string& input);

};


#endif