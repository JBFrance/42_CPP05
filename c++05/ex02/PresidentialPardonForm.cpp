#include "PresidentialPardonForm.hpp"

Pardon::Pardon() : AForm("pres", 25, 5)
{
        std::cout << GREEN << "Default pardon Constructor called\n" << RESET << std::endl;
};
    
Pardon::Pardon (std::string const &target ) : AForm("pardonForm", 25, 5)
{
    setTarget(target);
};

Pardon::Pardon(Pardon const &copy) : AForm(copy)
{
	*this = copy;
};

Pardon &Pardon::operator=( const Pardon &toCopy )
{
    if (this == &toCopy)
		return *this;
	AForm::operator=(toCopy);
	return *this;
};

Pardon::~Pardon()
{
    std::cout << RED << "Robotomy Destructor called" << RESET << std::endl;
};

void Pardon::execute(Bureaucrat const &executor) const
{
        if (executor.getGrade() > AForm::getGradeToExecute())
		throw GradeTooLowException();
	else if (getSigned() == "false")
		throw FormNotSignedException();
        std::cout << BLUE << getTarget() << " was pardoned by President of the Universe, Zaphod BeebleBrox. " << getTarget() << RESET << std::endl;
}