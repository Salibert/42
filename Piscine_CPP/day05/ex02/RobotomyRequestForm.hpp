#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        RobotomyRequestForm(std::string _name, int gradeExec, int gradeSigned);
    public:
        RobotomyRequestForm(void);
        virtual ~RobotomyRequestForm(void);
        RobotomyRequestForm(RobotomyRequestForm const & rhs);
        RobotomyRequestForm(std::string name);

        RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
        void execute(Bureaucrat const & executor) const;
};

#endif