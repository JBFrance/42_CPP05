//
// Created by Joshua Franceschi 01-24-2024
//

#include "Bureaucrat.hpp"

//Constructors & Destructor

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150)
{
    std::cout << GREEN << "Default constructor called" << RESET << std::endl;
};

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    std::cout << GREEN << "Paramatized constructor called" << RESET << std::endl;
    try
    {
        setGrade(grade);
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
};

Bureaucrat::Bureaucrat( const Bureaucrat& copy ) 
{
    std::cout << BLUE << "Copy constructor called" << std::endl;
    *this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) 
{
    std::cout << YELLOW << "Assignment called" << RESET <<std::endl;
    if (this != &copy)
    {   
        const_cast<std::string&>(_name) = copy._name;
        this->_grade = copy._grade;
    }
    return *this;
}

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

//ex02 additions
void    Bureaucrat::signForm(AForm &aform)
{
  try
	{
		aform.beSigned(*this);
		std::cout << _name << " signed " << aform.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn’t sign " << aform.getName() << " because " << e.what() << std::endl;
	}
};

void Bureaucrat::executeForm(const AForm &aform)
{
	try 
    {
		aform.execute(*this);
	}
	catch (std::exception &e) 
    {
		std::cout << _name << " cannot execute " << aform.getName() << " because " << e.what() << std::endl;
	}
};

//Exceptions

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high, outside range 150-1");
};

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low, outside range 150-1");
};