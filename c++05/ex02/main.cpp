//
// Created by Joshua Franceschi 01-28-2024
//

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

//
// Created by Joshua Franceschi 01-28-2024
//

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat bureaucrat("ash", 2);
    Shrubbery form1("shrub");
    Robotomy form2("Robotomy");
    Pardon  form3("Presidential");
//shrub
    bureaucrat.signForm(form1);
    bureaucrat.executeForm(form1);
//robot
    bureaucrat.signForm(form2);
    bureaucrat.executeForm(form2);
    bureaucrat.executeForm(form2);
    bureaucrat.executeForm(form2);
    bureaucrat.executeForm(form2);
//president pardon
    bureaucrat.signForm(form3);
    bureaucrat.executeForm(form3);
    return (0);
}