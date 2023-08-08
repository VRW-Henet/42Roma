#include <algorithm>
#include <map>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cmath>
#include <string>
#include <stdexcept>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &btc);
		~BitcoinExchange(){};
		
        void	doExchange(char *file);
};