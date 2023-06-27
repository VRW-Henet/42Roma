#ifndef REPLACER_HPP
# define REPLACER_HPP

# include <string>
# include <iomanip>
# include <iostream>
# include <fstream>
# include <sstream>

class Replacer
{
public:
	Replacer(std::string, std::string, std::string);
	~Replacer();

	std::string	getFile( void );
	std::string getStrToReplace( void );
	std::string getReplacer( void );

	void		fileReplace( void );

private:
	std::string	file;
	std::string	str_to_replace;
	std::string replacer;

	std::string	strReplace(std::string);
};

#endif