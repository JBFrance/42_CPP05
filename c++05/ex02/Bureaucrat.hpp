//
// Created by Joshua Franceschi 01-24-2024
//

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class AForm;

class Bureaucrat 
{
    private:
        std::string const _name;
        int _grade;
    public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &p); //copy constructor
    Bureaucrat& operator=( const Bureaucrat &p); //assignment constructor
    ~Bureaucrat(); //destructor

    std::string     getName() const;
    int             getGrade() const;
    void            setGrade(int toSet);
    void            incTry(int amount);
    void            decTry(int amount);
    void            decrement(void);
    void            increment(void);
    void            signForm(AForm &aform);
    void            executeForm(const AForm &aform);

    class GradeTooLowException : std::exception 
    {
        public:
        virtual const char *what() const throw();
    };

    class GradeTooHighException : std::exception
    {
        public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif