#include "Convert.hpp"

Converter::Converter()
{
	std::cout << "Default costructor called." << std::endl;
}

Converter::Converter(const Converter &rhs)
{
	if (this != &rhs)
		*this = rhs;
}

Converter::~Converter()
{
	std::cout << "Default destructor called." << std::endl;
}

Converter &Converter::operator=(const Converter &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	(void)rhs;
	return *this;
}

void Converter::convert(const std::string &input)
{
	std::string stypes[6] = {"-inff", "+inff", "nanf", "nan", "-inf", "+inf"};	
	std::string _char = "";
	int 		_int = 0;
	float		_float = 0;
	double		_double = 0;
	if (std::isprint(input[0]) && !std::isdigit(input[0]) && input.length() == 1)
	{
		_char = input[0];
		std::cout << "Char: " << _char << std::endl;
		std::cout << "Int: " << static_cast<int>(_char[0]) << std::endl;
		std::cout << "Float: " << static_cast<float>(_char[0]) << ".0f" << std::endl;
		std::cout << "Double: " << static_cast<double>(_char[0]) << ".0" << std::endl;
			return;
	}
	_int = std::atoi(input.c_str());

	if (input[input.length() - 1] == 'f')
	{
		_float = std::atof(input.c_str());
		_double = static_cast<double>(_float);
	}
	else
	{
		_double = std::atof(input.c_str());
		_float = _double = static_cast<double>(_double);
	}
	for (int i = 0; i < 6; i++)
		if(input == stypes[i])
		{
			_char = "impossible";
			break ;
		}

	if (_char == "" && std::isprint(_int))
	{
		_char = "'";
		_char += static_cast<char>(_int);
		_char += "'";
	}
	else if (_char == "")
		_char = "Not displayable";
	
	std::cout <<"Char: " << _char << std::endl;
	if (_char == "impossible")
		std::cout << "Int: " << "Impossible." << std::endl;
	else
		std::cout << "Int: " << _int << std::endl;
	if (_char == "impossible" && _float == 0)
	{
		std::cout << "Float: " << "Impossible." << std::endl;
		std::cout <<  "Double: " << "Impossible." << std::endl;
		return;
	}
	else
	{
		if (_char != "impossible" && _float - static_cast<int>(_float) == 0)
		{
			std::cout << "Float: " << _float << ".0f" << std::endl;
			std::cout << "Double: " << _double << ".0" << std::endl;			
		}
		else
		{
			std::cout << "Float: " << _float << ".0f" << std::endl;
			std::cout << "Double: " << _double << ".0" << std::endl;
		}
	}
	std::cout << std::endl;
}