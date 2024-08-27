//
// Created by Joshua Franceschi 01-24-2024
//

#include "Bureaucrat.hpp"

//Constructors & Destructor

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
};

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    std::cout << GREEN << "Paramatized constructor called" << RESET << std::endl;
        setGrade(grade);
};

Bureaucrat::Bureaucrat( const Bureaucrat& copy ) : _name(copy._name)
{
    std::cout << BLUE << "Copy constructor called" << std::endl;
    *this = copy;
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    std::cout << YELLOW << "Assignment called" << RESET <<std::endl;
    if (this != &copy)
    {
        const_cast<std::string&>(_name) = copy._name;
        this->_grade = copy._grade;
    }
    return *this;
};

Bureaucrat::~Bureaucrat()
{
    std::cout << RED << "Bureaucrat destructor called" << RESET << std::endl;
};

//Getters and Setters

std::string Bureaucrat::getName() const
{
    return _name;
};

int Bureaucrat::getGrade() const
{
    return _grade;
};

void    Bureaucrat::setGrade(int toSet)
{
    if (toSet < 1)
        throw(Bureaucrat::GradeTooHighException());
    else if (toSet > 150)
        throw (GradeTooLowException());
    _grade = toSet;
};

//increment && decrement

void    Bureaucrat::increment(void)
{
    try 
    {
        setGrade(_grade--);
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
};

void    Bureaucrat::decrement(void)
{
    try 
    {
        setGrade(_grade++);
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
};

//subject required overload operator

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
};

//Exceptions

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low, outside range 150-1");
};

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too High, outside range 150-1");
};