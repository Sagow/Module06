#include <iostream>
#include <string>
# include <stdint.h>
#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int	main()
{
	Data *data = new Data(5, 5.3f);

	std::cout << data << std::endl;
	std::cout << *data << std::endl;
	std::cout << deserialize(serialize(data)) << std::endl;
	std::cout << *deserialize(serialize(data)) << std::endl;

	delete data;
}