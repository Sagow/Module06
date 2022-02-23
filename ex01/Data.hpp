#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{

	public:

		Data();
		Data( Data const & src );
		~Data();
		Data &		operator=( Data const & rhs );

		Data(int a, float b);

		int	getA(void) const;
		float	getB(void) const;

	private:
		int _a;
		float _b;

};

std::ostream &			operator<<( std::ostream & o, Data const & i );

#endif /* ************************************************************ DATA_H */