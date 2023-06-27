#include "Replacer.hpp"

Replacer::Replacer(std::string file, std::string s1, std::string s2) : file(file), str_to_replace(s1), replacer(s2)
{
	std::cout << "Replacer constructor called\n";
}

Replacer::~Replacer(void)
{
	std::cout << "Replacer destructor called\n";
}

std::string Replacer::getFile(void)
{
	return this->file;
}

std::string Replacer::getStrToReplace(void)
{
	return this->str_to_replace;
}

std::string Replacer::getReplacer(void)
{
	return this->replacer;
}

void	Replacer::fileReplace(void)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		line;

	ifs.open(this->getFile());
	if (!ifs.is_open())
	{
		std::cout << "Error opening Input File";
		return ;
	}

	ofs.open(this->getFile() + ".replace", std::ios::trunc);
	if (!ofs.is_open())
	{
		std::cout << "Error opening Output File";
		return ;
	}

	while (std::getline(ifs, line))
	{
		ofs << this->strReplace(line);
		if (!ofs.eof())
			ofs << std::endl;
	}

	ifs.close();
	ofs.close();
}

std::string Replacer::strReplace(std::string line)
{
	std::stringstream new_str;

	int str_len = this->getStrToReplace().length();
	int	x = 0;
	int y = 0;

	while (line[x])
	{
		y = 0;

		while (line[x + y] == this->getStrToReplace()[y] && y < str_len)
			y++;

		if (y == str_len)
		{
			new_str << this->getReplacer();
			x += str_len - 1;
		}
		else
			new_str << line[x];
		x++;
	}

	return (new_str.str());
}