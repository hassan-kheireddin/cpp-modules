#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    ~Intern();
    Intern& operator=(const Intern& other);

    AForm* makeForm(const std::string& formName, const std::string& target);

private:
    typedef AForm* (Intern::*FormCreator)(const std::string& target);
    
    AForm* createShrubberyCreationForm(const std::string& target);
    AForm* createRobotomyRequestForm(const std::string& target);
    AForm* createPresidentialPardonForm(const std::string& target);
    
    struct FormType {
        std::string name;
        FormCreator creator;
    };
    
    static const FormType formTypes[];
    static const int formTypesCount;
};

#endif