#ifndef NUMBER_HPP
# define NUMBER_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include <math.h>
# include <climits>
# include <iomanip>

enum type {CHAR, INT, FLOAT, DOUBLE};

class Number
{

	public:

		Number();
		Number( Number const & src );
		~Number();
		Number &		operator=( Number const & rhs );

		Number(std::string nb);

		type			getType(void) const;
		void			setType(void);
		char			getC(void) const;
		int				getI(void) const;
		float			getF(void) const;
		double			getD(void) const;
		void			setArg(void);

		void			isChar(void);
		void			isInt(void);
		void			isFloat(void);
		void			isDouble(void);

		bool			getN_inf(void) const;
		bool			getP_inf(void) const;
		bool			getNan(void) const;

		void			printChar(std::ostream & o) const;
		void			printInt(std::ostream & o) const;
		void			printFloat(std::ostream & o) const;
		void			printDouble(std::ostream & o) const;


	private:


		std::string	_s;
		type				_type;
		char				_c;
		int					_i;
		float				_f;
		double				_d;
		bool				_n_inf;
		bool				_p_inf;
		bool				_nan;

};

std::ostream &			operator<<( std::ostream & o, Number const & i );

#endif /* ********************************************************** NUMBER_H */