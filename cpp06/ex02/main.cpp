#include "identify.hpp"
#include <iostream>

int main() {
    // Test with pointer
    Base* basePtr = generate();
    std::cout << "Identify by pointer: ";
    identify(basePtr);
    
    // Test with reference
    std::cout << "Identify by reference: ";
    identify(*basePtr);
    
    delete basePtr;
    
    // Test multiple times
    for (int i = 0; i < 5; i++) {
        Base* test = generate();
        std::cout << "Pointer ID: ";
        identify(test);
        std::cout << "Reference ID: ";
        identify(*test);
        std::cout << std::endl;
        delete test;
    }
    
    return 0;
}