#ifndef FORM_HPP
#define FORM_HPP

//
// Created by Joshua Franceschi 01-28-2024
//

#include <iostream>
#include "Bureaucrat.hpp"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Bureaucrat;

class Form
{
    private:
        std::string const   _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExec;
    public:
        //Constructors & destructors
        Form();
        Form &operator=(Form const &copy);
        Form(std::string const &nameToSign, int gradeSign);
        Form(std::string const &nameToSign, int gradeSign, int gradeExc);
        Form(const Form &copy);
        ~Form();

        int getGradeToSign() const;
        int getGradeToExecute() const;
        std::string getName() const;
        std::string    getSigned() const;
        void    beSigned(Bureaucrat const &bureaucrat);

        class GradeTooLowException : public std::exception 
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif