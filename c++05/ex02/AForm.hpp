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

class AForm
{
    private:
        std::string const   _name;
        std::string _target;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExec;
    public:
        //Constructors & destructors
        AForm();
        AForm(std::string const &nameToSign, int gradeSign);
        AForm(std::string const &nameToSign, int gradeSign, int gradeExc);
        AForm(const AForm &copy);
        AForm& operator=(const AForm &copy);
        
        virtual ~AForm();
        virtual std::string getTarget() const;
        virtual int         getGradeToSign() const;
        virtual int         getGradeToExecute() const;
        virtual std::string getName() const;
        virtual std::string getSigned() const;
        virtual void        beSigned(Bureaucrat const &bureaucrat);
        virtual void        setTarget(const std::string &target);
        virtual void        execute(Bureaucrat const &executor) const = 0;

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

        class FormNotSignedException : public std::exception 
        {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &Aform);

#endif