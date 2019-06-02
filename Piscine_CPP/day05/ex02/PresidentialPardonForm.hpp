#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        PresidentialPardonForm(std::string _name, int gradeExec, int gradeSigned);
    public:
        PresidentialPardonForm(void);
        virtual ~PresidentialPardonForm(void);
        PresidentialPardonForm(PresidentialPardonForm const & rhs);
        PresidentialPardonForm(std::string name);

        PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
        void execute(Bureaucrat const & executor) const;
};

#endif