//
// Created by Joshua Franceschi 01-24-2024
//

#include "Bureaucrat.hpp"

int main()
{
    try 
    {   
        Bureaucrat *a = new Bureaucrat("Blarg", 50);
        Bureaucrat b = Bureaucrat("Bruno", 100);
        std::cout << b.getName() << std::endl;
        Bureaucrat c(b);
        std::cout << c.getName() << std::endl;
        Bureaucrat d = c;
        std::cout << d.getName() << std::endl;

        delete a;
    } 
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    //system("leaks Bureaucrat");
};