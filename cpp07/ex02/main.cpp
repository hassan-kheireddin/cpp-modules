#include <iostream>
#include "Array.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main() {
    std::cout << BLUE << "--- Test 1: Default Constructor ---" << RESET << std::endl;
    Array<int> empty;
    std::cout << "Size of empty array: " << empty.size() << std::endl;

    std::cout << std::endl << BLUE << "--- Test 2: Parameterized Constructor & Operator[] ---" << RESET << std::endl;
    Array<int> numbers(5);
    std::cout << "Size of numbers array: " << numbers.size() << std::endl;
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        numbers[i] = i * 10;
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    std::cout << std::endl << BLUE << "--- Test 3: Copy Constructor (Deep Copy) ---" << RESET << std::endl;
    Array<int> copyOfNumbers(numbers);
    std::cout << "Original array after copy: ";
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl << "Copy array: ";
    for (unsigned int i = 0; i < copyOfNumbers.size(); ++i) {
        std::cout << copyOfNumbers[i] << " ";
    }
    std::cout << std::endl;

    // Modify the copy to show independence
    copyOfNumbers[0] = 999;
    std::cout << "After modifying copy, original[0] is still: " << numbers[0] << std::endl;
    std::cout << "Copy[0] is now: " << copyOfNumbers[0] << std::endl;

    std::cout << std::endl << BLUE << "--- Test 4: Assignment Operator (Deep Copy) ---" << RESET << std::endl;
    Array<int> assignedArray;
    assignedArray = numbers;
    std::cout << "Assigned array: ";
    for (unsigned int i = 0; i < assignedArray.size(); ++i) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl << BLUE << "--- Test 5: Out of Bounds Exception ---" << RESET << std::endl;
    try {
        std::cout << "Trying to access numbers[10]..." << std::endl;
        numbers[10] = 5;
        std::cout << GREEN << "Success? (This shouldn't print)" << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cout << RED << "Caught an exception! (This is good)" << RESET << std::endl;
    }

    std::cout << std::endl << BLUE << "--- Test 6: Array of Strings ---" << RESET << std::endl;
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "World";
    strings[2] = "!";
    for (unsigned int i = 0; i < strings.size(); ++i) {
        std::cout << strings[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}