#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter::Type ScalarConverter::detectType(const std::string &literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return PSEUDO;
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return PSEUDO;

	if (literal.length() == 1 && !isdigit(literal[0]))
		return CHAR;

	char *endPtr = NULL;
	std::strtod(literal.c_str(), &endPtr);
	if (*endPtr == 'f' && *(endPtr + 1) == '\0')
		return FLOAT;
	if (*endPtr == '\0')
		return DOUBLE;

	long int li = std::strtol(literal.c_str(), &endPtr, 10);
	if (*endPtr == '\0' && li >= INT_MIN && li <= INT_MAX)
		return INT;

	return INVALID;
}

void ScalarConverter::fromChar(const std::string &literal)
{
	char c = literal[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void ScalarConverter::fromInt(const std::string &literal)
{
	long int li = std::strtol(literal.c_str(), NULL, 10);
	if (li < INT_MIN || li > INT_MAX)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	int i = static_cast<int>(li);

	if (i < CHAR_MIN || i > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else if (i < 32 || i > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::fromFloat(const std::string &literal)
{
	char *endPtr;
	float f = std::strtof(literal.c_str(), &endPtr);

	if (f < CHAR_MIN || f > CHAR_MAX || std::isnan(f) || std::isinf(f))
		std::cout << "char: impossible" << std::endl;
	else if (f < 32 || f > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

	if (f < INT_MIN || f > INT_MAX || std::isnan(f) || std::isinf(f))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;

	std::cout << "float: " << f;
	if (!std::isnan(f) && !std::isinf(f) && f == static_cast<int64_t>(f))
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(f);
	if (!std::isnan(f) && !std::isinf(f) && f == static_cast<int64_t>(f))
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

void ScalarConverter::fromDouble(const std::string &literal)
{
	char *endPtr;
	double d = std::strtod(literal.c_str(), &endPtr);

	if (d < CHAR_MIN || d > CHAR_MAX || std::isnan(d) || std::isinf(d))
		std::cout << "char: impossible" << std::endl;
	else if (d < 32 || d > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

	if (d < INT_MIN || d > INT_MAX || std::isnan(d) || std::isinf(d))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	float f = static_cast<float>(d);
	std::cout << "float: " << f;
	if (!std::isnan(f) && !std::isinf(f) && f == static_cast<int64_t>(f))
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;

	std::cout << "double: " << d;
	if (!std::isnan(d) && !std::isinf(d) && d == static_cast<int64_t>(d))
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

void ScalarConverter::fromPseudo(const std::string &literal)
{
	std::string pseudo = literal;
	if (pseudo == "nanf" || pseudo == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (pseudo == "+inff" || pseudo == "+inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (pseudo == "-inff" || pseudo == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &literal)
{
	Type t = detectType(literal);

	switch (t)
	{
		case CHAR:
			fromChar(literal);
			break;
		case INT:
			fromInt(literal);
			break;
		case FLOAT:
			fromFloat(literal);
			break;
		case DOUBLE:
			fromDouble(literal);
			break;
		case PSEUDO:
			fromPseudo(literal);
			break;
		case INVALID:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			break;
	}
}