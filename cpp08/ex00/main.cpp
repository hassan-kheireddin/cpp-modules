#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    // Test with vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found value 3 at position: " << std::distance(vec.begin(), it) << std::endl;
        std::cout << "Value at iterator: " << *it << std::endl; // Added usage
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 42); // Store iterator
        std::cout << "Found value 42 at position: " << std::distance(vec.begin(), it) << std::endl;
        std::cout << "Value at iterator: " << *it << std::endl; // Added usage
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // Test with list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    try {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found value 20 in list" << std::endl;
        std::cout << "Value at iterator: " << *it << std::endl; // Added usage
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}