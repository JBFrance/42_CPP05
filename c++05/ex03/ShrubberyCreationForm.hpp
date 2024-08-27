#ifndef SHRUBBERYCREATIONFORM 
# define SHRUBBERYCREATIONFORM

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class Shrubbery : public AForm
{
    private:
        std::string target;
    public:
        Shrubbery();
        Shrubbery (std::string const &target );
        Shrubbery(Shrubbery const &copy);
        Shrubbery& operator=( const Shrubbery &toCopy );
        ~Shrubbery();

        void execute(Bureaucrat const &executor) const;
        static AForm *clone(std::string target);
};

#endif
//sign 145, exec 137