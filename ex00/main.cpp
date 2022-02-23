#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	int	i = 0;
	if (ac != 2)
	{
		std::cout << "Merci de donner un, et un seul, normbre." << std::endl;
		return (0);
	}
	if (av[1][i] == '-')
	while (av[1][i] >= '0' && av[1][i] <= '9')
		i++;
	if

}