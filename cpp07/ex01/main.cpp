#include <iostream>
#include "iter.hpp"

// Template function to print any type
template <typename T>
void printElement(const T &element) {
    std::cout << element << " ";
}

// Function to increment an int (non-template)
void incrementInt(int &n) {
    n++;
}

// Function to make a string uppercase (non-template)
void makeUppercase(std::string &str) {
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = std::toupper(str[i]);
    }
}

int main() {
    // Test with int array
    int intArr[] = {1, 2, 3, 4, 5};
    unsigned int intLength = sizeof(intArr) / sizeof(intArr[0]);

    std::cout << "Original int array: ";
    iter(intArr, intLength, printElement<int>);
    std::cout << std::endl;

    iter(intArr, intLength, incrementInt);
    std::cout << "After increment: ";
    iter(intArr, intLength, printElement<int>);
    std::cout << std::endl << std::endl;

    // Test with string array
    std::string strArr[] = {"hello", "world", "from", "iter"};
    unsigned int strLength = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "Original string array: ";
    iter(strArr, strLength, printElement<std::string>);
    std::cout << std::endl;

    iter(strArr, strLength, makeUppercase);
    std::cout << "After uppercase: ";
    iter(strArr, strLength, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}