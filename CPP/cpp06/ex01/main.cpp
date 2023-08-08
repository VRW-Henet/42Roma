#include <iostream>

struct Data
{
	std::string stringa;
	int			integ;
};

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast <uintptr_t >(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast <Data *>(raw));
}

int main(void)
{
	Data *hello = new Data;
	hello->integ = 42;
	hello->stringa = "quarantadue";

	std::cout << "BEFORE: " << std::endl;
	std::cout << hello->integ << std::endl;
	std::cout << hello->stringa << std::endl;

	std::cout << "AFTER: " << std::endl;
	uintptr_t serial = serialize(hello);
	std::cout << "SERIALIZE " << serialize(hello) << std::endl;
	std::cout << "DESERIALIZE " << deserialize(serial) << std::endl;
}