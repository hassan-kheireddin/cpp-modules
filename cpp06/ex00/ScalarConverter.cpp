#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>

void ScalarConverter::convert(const std::string& literal) {
    // Check for empty input
    if (literal.empty()) {
        std::cout << "Error: empty input" << std::endl;
        return;
    }

    // Determine the type of the literal
    char *endptr;
    double value;
    std::string str = literal;

    // Check for special float cases
    if (str == "-inff" || str == "+inff" || str == "nanf") {
        str = str.substr(0, str.size() - 1);
    }
    // Check for special double cases
    else if (str == "-inf" || str == "+inf" || str == "nan") {
        // No modification needed
    }
    // Check for char case
    else if (str.length() == 1 && !isdigit(str[0])) {
        value = static_cast<double>(str[0]);
        goto convert;
    }

    value = strtod(str.c_str(), &endptr);
    
    // Check if the entire string was converted
    if (*endptr != '\0' && !(*endptr == 'f' && *(endptr + 1) == '\0')) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

convert:
    // Convert to char
    std::cout << "char: ";
    if (isnan(value) || isinf(value) || value < CHAR_MIN || value > CHAR_MAX) {
        std::cout << "impossible" << std::endl;
    } else if (!isprint(static_cast<char>(value))) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    }

    // Convert to int
    std::cout << "int: ";
    if (isnan(value) || isinf(value) || value < INT_MIN || value > INT_MAX) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(value) << std::endl;
    }

    // Convert to float
    std::cout << "float: ";
    if (isnan(value)) {
        std::cout << "nanf" << std::endl;
    } else if (isinf(value)) {
        std::cout << (value < 0 ? "-" : "+") << "inff" << std::endl;
    } else {
        float f = static_cast<float>(value);
        if (f == floorf(f)) {
            std::cout << f << ".0f" << std::endl;
        } else {
            std::cout << f << "f" << std::endl;
        }
    }

    // Convert to double
    std::cout << "double: ";
    if (isnan(value)) {
        std::cout << "nan" << std::endl;
    } else if (isinf(value)) {
        std::cout << (value < 0 ? "-" : "+") << "inf" << std::endl;
    } else {
        if (value == floor(value)) {
            std::cout << value << ".0" << std::endl;
        } else {
            std::cout << value << std::endl;
        }
    }
}