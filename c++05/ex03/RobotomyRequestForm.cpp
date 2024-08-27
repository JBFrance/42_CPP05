#include "RobotomyRequestForm.hpp"
    
Robotomy::Robotomy() : AForm("Robotomy", 72, 45)
{
    std::cout << GREEN << "Default Robotomy Constructor called" << RESET << std::endl;
};
    
Robotomy::Robotomy (std::string const &target ) : AForm("RobotomyForm", 72, 45)
{
    setTarget(target);
};

Robotomy::Robotomy(Robotomy const &copy) : AForm(copy)
{
	*this = copy;
};

Robotomy &Robotomy::operator=( const Robotomy &toCopy )
{
    if (this == &toCopy)
		return *this;
	AForm::operator=(toCopy);
	return *this;
};

Robotomy::~Robotomy()
{
    std::cout << RED << "Robotomy Destructor called" << RESET << std::endl;
};

void Robotomy::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > AForm::getGradeToExecute())
		throw GradeTooLowException();
	else if (getSigned() == "false")
		throw FormNotSignedException();
    std::cout << "Drilling noises" << std::endl;
    if ((rand() % 2) != 0)
        std::cout << BLUE << getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << BLUE << getTarget() << " robotomy failed, dang" << std::endl;
};

AForm *Robotomy::clone(std::string target)
{
	std::cout << GREEN << "Robotomy Clone Called" << RESET << std::endl;
	AForm *b = new Robotomy(target);
	return (b);
};