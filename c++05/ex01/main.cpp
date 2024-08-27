//
// Created by Joshua Franceschi 01-28-2024
//

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat a("a", 155);
        std::cout << a.getName() << std::endl;
	    std::cout << a.getGrade() << std::endl;

    } 
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try 
    {
        Bureaucrat bureaucrat("ash", 12);
        Form form("formName", 10);

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
    // Bureaucrat bureaucrat("ash", 2);
    // Form form("formName", 10, 100);
    // bureaucrat.signForm(form);
    system("leaks Forms");
	return 0;
}