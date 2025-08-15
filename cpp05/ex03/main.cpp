#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
    Bureaucrat bob("Bob", 1);
    AForm* form;

    // Test creating known forms
    form = someRandomIntern.makeForm("shrubbery creation", "home");
    if (form) {
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }

    form = someRandomIntern.makeForm("presidential pardon", "Zaphod");
    if (form) {
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }

    // Test unknown form
    form = someRandomIntern.makeForm("unknown form", "target");
    if (form) {
        delete form;
    }

    return 0;
}