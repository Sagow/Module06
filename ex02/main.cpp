#include <iostream>
#include <string>
#include <math.h>
#include <time.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int	i = rand() % 3;
	std::cout << "generate va creer une base " << (char)('A' + i) << std::endl;
	if (i == 0)
		return (new A);
	if (i == 1)
		return (new B);
	return (new C);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "C'est une base A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "C'est une base B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C'est une base C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "C'est une base A" << std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "C'est une base B" << std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C'est une base C" << std::endl;
	}
	catch(const std::exception& e) {}
}

int	main()
{
	srand(time(NULL));
	std::cout << "Par adresse puis par reference:" << std::endl;
	for (int i = 0; i < 10 ; i++)
	{
		Base *tmp = generate();
		identify(tmp);
		identify(*tmp);
	}
	return (0);
}