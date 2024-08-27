#include "AForm.hpp"
#include "Bureaucrat.hpp"

//
// Created by Joshua Franceschi 01-28-2024
//

AForm::AForm() : _name("default"), _gradeToSign(150), _gradeToExec(150)
{
    _signed = false;
    std::cout << GREEN << "Form default constructor called" << RESET << std::endl;
}

AForm::AForm(std::string const &name, int gradeSign) : _name(name), _gradeToSign(gradeSign), _gradeToExec(150)
{
	if (gradeSign < 1)
		throw AForm::GradeTooHighException();
	else if (gradeSign > 150)
		throw AForm::GradeTooLowException();
	else
		this->_signed = false;
}

AForm::AForm(std::string const &nameToSign, int gradeSign, int gradeExc) : _name(nameToSign), _gradeToSign(gradeSign), _gradeToExec(gradeExc)
{
	std::cout << GREEN << "AForm constructor called" << RESET << std::endl;
	
    if (gradeSign < 1 || gradeExc < 1)
		throw AForm::GradeTooHighException();
	else if (gradeSign > 150 || gradeExc > 150)
		throw AForm::GradeTooLowException();
	else
		this->_signed = false;
};

AForm& AForm::operator=(const AForm &copy)
{
    std::cout << YELLOW << "Assignment called" << RESET << std::endl;
	if (this != &copy)
	{
		const_cast<int&>(_gradeToSign) = copy._gradeToSign;
		const_cast<int&>(_gradeToExec) = copy._gradeToExec;
		const_cast<std::string&>(_name) = copy._name;
    	this->_signed = copy._signed;
		this->_target = copy._target;
	}
	return (*this);
};

AForm::AForm(AForm const &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
	*this = copy;
}

AForm::~AForm()
{
    std::cout << RED << "AForm destructor called" << RESET << std::endl;
};

//Non constructor functions

int AForm::getGradeToSign() const
{
    return (_gradeToSign);
};

int AForm::getGradeToExecute() const
{
    return (_gradeToExec);
};

std::string AForm::getName() const
{
    return (_name);
};

void    AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign)
        _signed = true;
    else
        throw (GradeTooLowException());
};

std::string AForm::getSigned() const
{
	if (_signed == true)
		return "True";
	else
		return "False";
};

std::ostream &operator<<(std::ostream &out, const AForm &aform)
{
	out << aform.getName() << ", form signed = " << aform.getSigned() << std::endl;
	return (out);
};

std::string AForm::getTarget() const
{
	return _target;
};

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed";
};

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high, outside range 150-1";
};

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low, outside range 150-1";
};

void AForm::setTarget(const std::string &target)
{
	_target = target;
};