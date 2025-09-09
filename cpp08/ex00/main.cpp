#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Value at iterator: " << *it << std::endl; // Added usage
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    //not found case
    try {
        std::vector<int>::iterator it = easyfind(vec, 42); // Store iterator
        std::cout << "Value at iterator: " << *it << std::endl; // Added usage
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}