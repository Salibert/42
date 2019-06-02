#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm(NULL, 0, 0) { return; }

RobotomyRequestForm::~RobotomyRequestForm(void) { return; }

RobotomyRequestForm::RobotomyRequestForm(std::string name, int gradeExec, int gradeSigned) :
    AForm(name, gradeExec, gradeSigned) { return ;}

RobotomyRequestForm::RobotomyRequestForm(std::string name) :
    AForm(name, 45, 72) { return ;}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & rhs) {
    *this = rhs;
    return;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getGradeExe())
        throw AForm::GradeTooLowException();
    if (rand() % 2 == 0)
        std::cout << this->getName() << "  BRR BRZZZZZZ" << std::endl;
    else
        std::cout << "failure" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
    if (this != &rhs) {
        this->setIsSigned(rhs.getIsSigned());
    }
    return *this;
}