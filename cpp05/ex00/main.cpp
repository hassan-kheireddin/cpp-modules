#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        // Test valid bureaucrat
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;

        // Test increment
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;

        // Test decrement
        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;

        // Test too high grade
        Bureaucrat high("High", 0);
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        // Test too low grade
        Bureaucrat low("Low", 151);
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat valid("Valid", 1);
        std::cout << valid << std::endl;
        valid.incrementGrade(); // Should throw
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

/*
The try Block

    The try block is used to enclose code that may throw an exception.
    In this case, the line Bureaucrat low("Low", 151); attempts to create a Bureaucrat object with a grade of 151.
    According to the exercise requirements, the valid range for a bureaucrat's grade is 1 (highest) to
    150 (lowest). A grade of 151 is invalid and should trigger an exception.


 The catch Block

    If an exception is thrown inside the try block, the program jumps to the catch block.
    The catch block specifies the type of exception to catch. Here, it catches any exception derived from std::exception (which includes your custom exceptions like GradeTooHighException and GradeTooLowException).
    Inside the catch block:
        e.what() retrieves the error message associated with the exception. This message is defined in the overridden what() method of your custom exception class.
        The error message is printed to the standard error stream (std::cerr).

This helps prevent undefined behavior or crashes caused by invalid input.
*/