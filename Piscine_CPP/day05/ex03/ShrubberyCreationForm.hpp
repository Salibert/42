#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
class ShrubberyCreationForm : public AForm {
    private:
        ShrubberyCreationForm(std::string name, int gradeExec, int gradeSigned);
        ShrubberyCreationForm(void);
    public:
        virtual ~ShrubberyCreationForm(void);
        ShrubberyCreationForm(ShrubberyCreationForm const & rhs);
        ShrubberyCreationForm(std::string name);

        ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
        virtual void execute(Bureaucrat const & executor) const;
};

#endif