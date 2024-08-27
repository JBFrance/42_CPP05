#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>

class Robotomy : public AForm
{
    private:
        std::string target;
    public:
        Robotomy();
        Robotomy (std::string const &target );
        Robotomy(Robotomy const &copy);
        Robotomy& operator=( const Robotomy &toCopy );
        ~Robotomy();

        void execute(Bureaucrat const &executor) const;
};

#endif
//sign 72, exec 45