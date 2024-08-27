#include "ShrubberyCreationForm.hpp"

Shrubbery::Shrubbery() : AForm("Shrubbery", 145, 137)
{
    std::cout << GREEN << "Shrubbery Constructor called" << RESET << std::endl;
};

Shrubbery::Shrubbery (std::string const &target ) : AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << GREEN << "Shrubbery Name constructor called" << RESET << std::endl;
    setTarget(target);
};

Shrubbery::Shrubbery(Shrubbery const &copy) : AForm(copy)
{
	*this = copy;
};

Shrubbery &Shrubbery::operator=( const Shrubbery &toCopy )
{
    if (this == &toCopy)
		return *this;
	AForm::operator=(toCopy);
	return *this;
};

Shrubbery::~Shrubbery()
{
    std::cout << RED << "Shrubbery Destructor called" << RESET << std::endl;
};
//derived functions

void Shrubbery::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > AForm::getGradeToExecute())
		throw GradeTooLowException();
	else if (getSigned() == "false")
		throw FormNotSignedException();
	std::ofstream outputFile(AForm::getTarget() + "_shrubbery");
    outputFile << GREEN ; 
    outputFile << "   \\  /" <<std::endl;
    outputFile << "   - * -" << std::endl;
    outputFile << "    /0\\" << std::endl;
    outputFile << "   /~*~~\\" << std::endl;
    outputFile << "  /~O~O~~*\\" << std::endl;
    outputFile << " /~O~~*~O~~O\\" << std::endl;
    outputFile << "/O~*~~O~*~~O~~\\" << std::endl;
    outputFile << "~`~`~`|~|`~`~`~" << std::endl;
    outputFile << "     |===|" << std::endl;
    outputFile << "     .___." << RESET << std::endl;
    outputFile.close();
};
