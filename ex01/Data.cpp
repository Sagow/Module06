#include "Data.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Data::Data()
{
	_a = 0;
	_b = 0;
}

Data::Data(int a, float b)
{
	_a = a;
	_b = b;
}

Data::Data( const Data & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Data::~Data()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Data &				Data::operator=( Data const & rhs )
{
	_a = rhs.getA();
	_b = rhs.getB();
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Data const & i )
{
	o << "a = " << i.getA() << ", b = " << i.getB();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int	Data::getA(void) const
{
	return (_a);
}

float	Data::getB(void) const
{
	return (_b);
}


/* ************************************************************************** */