#include "Fixed.hpp"

int main(void) {
    Fixed a; // Calls the default constructor
    Fixed b(a); // Calls the copy constructor
    Fixed c; // Calls the default constructor
    c = b; // Calls the copy assignment operator

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}