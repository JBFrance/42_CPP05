#include "Form.hpp"
#include "Bureaucrat.hpp"
//
// Created by Joshua Franceschi 01-28-2024
//

Form::Form() : _name("default"), _gradeToSign(150), _gradeToExec(150)
{
    _signed = false;
    std::cout << GREEN << "Form default constructor called" << RESET << std::endl;
}

Form::Form(std::string const &name, int gradeSign) : _name(name), _gradeToSign(gradeSign), _gradeToExec(0)
{
	if (gradeSign < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150)
		throw Form::GradeTooLowException();
	else
		this->_signed = false;
};

Form::Form(std::string const &nameToSign, int gradeSign, int gradeExc) : _name(nameToSign), _gradeToSign(gradeSign), _gradeToExec(gradeExc)
{
    if (gradeSign < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150)
		throw Form::GradeTooLowException();
	else
		this->_signed = false;
	if (gradeExc < gradeSign)
		throw Form::GradeTooLowException();
	else
		this->_signed = false;
};
Form &Form::operator=(Form const &copy)
{
	if (this != &copy)
	{
		const_cast<int&>(_gradeToSign) = copy._gradeToSign;
		const_cast<int&>(_gradeToExec) = copy._gradeToExec;
		this->_signed = copy._signed;
	}
	return (*this);
};

Form::Form(const Form &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
    std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
    *this = copy;
};

Form::~Form()
{
    std::cout << RED << "Form destructor called" << RESET << std::endl;
};

//Non constructor functions

int Form::getGradeToSign() const
{
    return (_gradeToSign);
};

int Form::getGradeToExecute() const
{
    return (_gradeToExec);
};

std::string Form::getName() const
{
    return (_name);
};

void    Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign)
        _signed = true;
    else
        throw Bureaucrat::GradeTooLowException();
};

std::string Form::getSigned() const
{
	if (_signed == true)
		return "True";
	else
		return "False";
};

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << ", form signed = " << form.getSigned() << std::endl;
	return (out);
};

//Exceptions

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low, outside range 150-1");
};

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high, outside range 150-1");
};