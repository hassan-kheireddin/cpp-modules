#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        // Test valid forms
        Form taxForm("Tax Return", 50, 40);
        Form leaveForm("Leave Application", 30, 20);
        std::cout << taxForm << std::endl;
        std::cout << leaveForm << std::endl;

        // Test invalid forms
        try {
            Form highForm("Top Secret", 0, 1);
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        try {
            Form lowForm("Trivial", 151, 150);
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // Test signing forms
        Bureaucrat boss("Boss", 1);
        Bureaucrat employee("Employee", 60);

        boss.signForm(taxForm);
        employee.signForm(leaveForm);

        std::cout << "\nAfter signing attempts:\n";
        std::cout << taxForm << std::endl;
        std::cout << leaveForm << std::endl;

        // Test successful signing
        Bureaucrat manager("Manager", 30);
        manager.signForm(leaveForm);
        std::cout << leaveForm << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}