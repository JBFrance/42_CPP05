#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class Pardon : public AForm
{
    private:
        std::string target;
    public:
        Pardon();
        Pardon (std::string const &target );
        Pardon(Pardon const &copy);
        Pardon& operator=( const Pardon &toCopy );
        ~Pardon();

        void execute(Bureaucrat const &executor) const;
        static AForm *clone(std::string target);
};

// sign 25, exec 5

#endif