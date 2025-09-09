#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    // Test from the subject
    std::cout << "=== Test from subject ===" << std::endl;
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    // Test with 15,000 numbers
    std::cout << "\n=== Test with 15,000 numbers ===" << std::endl;
    Span bigSpan(15000);
    std::srand(std::time(0));
    for (int i = 0; i < 15000; ++i) {
        bigSpan.addNumber(std::rand());
    }
    std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

    // Test adding a range of numbers
    std::cout << "\n=== Test adding a range ===" << std::endl;
    Span rangeSpan(10);
    std::vector<int> vec;
    vec.push_back(100);
    vec.push_back(200);
    vec.push_back(00);

    rangeSpan.addNumbers(vec.begin(), vec.end());
    std::cout << "Shortest span: " << rangeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << rangeSpan.longestSpan() << std::endl;

    // Test exceptions
    std::cout << "\n=== Test exceptions ===" << std::endl;
    Span smallSpan(1);
    smallSpan.addNumber(42);
    try {
        smallSpan.addNumber(43);
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    Span emptySpan(10);
    try {
        emptySpan.shortestSpan();
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}