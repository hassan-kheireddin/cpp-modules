#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

const Intern::FormType Intern::formTypes[] = {
    {"shrubbery creation", &Intern::createShrubberyCreationForm},
    {"robotomy request", &Intern::createRobotomyRequestForm},
    {"presidential pardon", &Intern::createPresidentialPardonForm}
};

const int Intern::formTypesCount = sizeof(Intern::formTypes) / sizeof(Intern::FormType);

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    for (int i = 0; i < formTypesCount; ++i) {
        if (formName == formTypes[i].name) {
            AForm* form = (this->*formTypes[i].creator)(target);
            std::cout << "Intern creates " << formName << std::endl;
            return form;
        }
    }
    std::cout << "Intern cannot create " << formName << " form (unknown form type)" << std::endl;
    return NULL;
}