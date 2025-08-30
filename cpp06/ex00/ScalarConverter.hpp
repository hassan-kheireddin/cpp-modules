#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

		enum Type { CHAR, INT, FLOAT, DOUBLE, PSEUDO, INVALID };

		static Type	detectType(const std::string &literal);
		static void	fromChar(const std::string &literal);
		static void	fromInt(const std::string &literal);
		static void	fromFloat(const std::string &literal);
		static void	fromDouble(const std::string &literal);
		static void	fromPseudo(const std::string &literal);

	public:
		static void convert(const std::string &literal);
};

#endif