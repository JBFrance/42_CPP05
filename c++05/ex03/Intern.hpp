#ifndef INTER_HPP
#define INTER_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstring>

class Intern
{
public:
    Intern();
    ~Intern();
    Intern(const Intern &copy);
    Intern& operator=( const Intern &copy);

    AForm *makeForm(std::string name, std::string target);
};


#endif