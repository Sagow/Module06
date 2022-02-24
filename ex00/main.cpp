#include <iostream>
#include <string>
#include "Number.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Merci de donner un, et un seul, normbre." << std::endl;
		return (0);
	}
	Number nb(av[1]);
	nb.setType();
	nb.setArg();
	std::cout << nb;
	return (0);
}
