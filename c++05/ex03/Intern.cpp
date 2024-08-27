#include "Intern.hpp"

Intern::Intern()
{
    std::cout << GREEN << "Inter Default Constructor called" << RESET << std::endl;
};

Intern::~Intern()
{
    std::cout << RED << "Inter Destructor called" << RESET << std::endl;
};

Intern::Intern( const Intern& copy ) 
{
    std::cout << BLUE << "Copy constructor called" << std::endl;
    *this = copy;
};

Intern& Intern::operator=(const Intern& copy) 
{
    std::cout << YELLOW << "Assignment called" << RESET <<std::endl;
    (void)copy;
    return *this;
};

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(*forms[3])(std::string) = {Shrubbery::clone, Robotomy::clone, Pardon::clone};
    for (int i = 0; i < 3; i++)
    {
        if (name == names[i])
            return (forms[i](target));
    }
    std::cout << "Invalid Name Provided" << std::endl;
    return (NULL);
};