#include "Number.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Number::Number() : _s("0"), _n_inf(false), _p_inf(false), _nan(false)
{
}

Number::Number(std::string nb) : _s(nb), _n_inf(false), _p_inf(false), _nan(false)
{
}

Number::Number( const Number & src )
{
	_type = src._type;
	_c = src._c;
	_i = src._i;
	_f = src._f;
	_d = src._d;
	_n_inf = src._n_inf;
	_p_inf = src._p_inf;
	_nan = src._nan;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Number::~Number()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Number &				Number::operator=( Number const & rhs )
{
	_type = rhs._type;
	_c = rhs._c;
	_i = rhs._i;
	_f = rhs._f;
	_d = rhs._d;
	_n_inf = rhs._n_inf;
	_p_inf = rhs._p_inf;
	_nan = rhs._nan;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Number const & i )
{
	i.printChar(o);
	i.printInt(o);
	i.printFloat(o);
	i.printDouble(o);
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	Number::printChar(std::ostream & o) const
{
	o << "Char : ";
	if (!(getN_inf() || getP_inf() || getNan()) && getI() >= CHAR_MIN && getI() <= CHAR_MAX)
	{
		if (isprint(getC()))
			o << getC();
		else
			o << "Non displayable";
	}
	else
			o << "Impossible";
	o << std::endl;
}

void	Number::printInt(std::ostream & o) const
{
	o << std::endl << "Int : ";
	if (!(getN_inf() || getP_inf() || getNan()) && atol(_s.c_str()) >= (long)INT_MIN && atol(_s.c_str()) <= (long)INT_MAX)
	{
		o << getI();
	}
	else
		o << "Impossible";
	o << std::endl;
}

void	Number::printFloat(std::ostream & o) const
{
	o << std::endl << "Float : ";
	if (getN_inf())
		o << "-inf";
	else if (getP_inf())
		o << "+inf";
	else if (getNan())
		o << "nan";
	else
		o << std::fixed << std::setprecision(1) << _f;
	o << "f" << std::endl;
}

void	Number::printDouble(std::ostream & o) const
{
	o << std::endl << "Double : ";
	if (getN_inf())
		o << "-inf";
	else if (getP_inf())
		o << "+inf";
	else if (getNan())
		o << "nan";
	else
		o << std::fixed << std::setprecision(1) << getD();
	o << std::endl;
}

void	Number::setType()
{
	bool	f = false;
	bool	point = false;
	int		i = 0;

	if (_s.length() == 1 && (_s[0] < '0' || _s[0] > '9'))
	{
		_type = CHAR;
	}
	else
	{
		if (!_s.compare("-inff") || !_s.compare("-inf"))
			_n_inf = true;
		if (!_s.compare("+inff") || !_s.compare("+inf"))
			_p_inf = true;
		if (!_s.compare("nanf") || !_s.compare("nan"))
			_nan = true;
		while (_s[i])
		{
			if (_s[i] == '.')
				point = true;
			i++;
		}
		if (_s[i] == 'f' && _s != "-inf" && _s != "+inf")
			f = true;
		if (f)
			_type = FLOAT;
		else if (point)
			_type = DOUBLE;
		else
			_type = INT;
	}
	
}

type	Number::getType() const
{
	return (_type);
}

char	Number::getC() const
{
	return (_c);
}

int		Number::getI() const
{
	return (_i);
}

float	Number::getF() const
{
	return (_f);
}

double	Number::getD() const
{
	return (_d);
}

void	Number::isChar()
{
	_c = _s[0];
	_i = static_cast<int>(_c);
	_f = static_cast<float>(_i);
	_d = static_cast<double>(_i);
}

void	Number::isInt()
{
	_i = atoi(_s.c_str());
	_c = static_cast<int>(_i);
	_f = static_cast<float>(_i);
	_d = static_cast<double>(_i);
}

void	Number::isFloat()
{
	_c = 0;
	_f = static_cast<float>(atof(_s.c_str()));
	_i = static_cast<int>(_f);
	_d = static_cast<double>(_f);
}

void	Number::isDouble()
{
	_c = 0;
	_d = atof(_s.c_str());
	_i = static_cast<int>(_d);
	_f = static_cast<float>(_d);
}

void	Number::setArg()
{
	if (_type == CHAR)
		isChar();
	if (_type == INT)
		isInt();
	if (_type == FLOAT)
		isFloat();
	if (_type == DOUBLE)
		isDouble();
}

bool	Number::getN_inf(void) const
{
	return(_n_inf);
}

bool	Number::getP_inf(void) const
{
	return(_p_inf);
}

bool	Number::getNan(void) const
{
	return(_nan);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */