#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm(NULL, NULL, 0, 0) { return; }

PresidentialPardonForm::~PresidentialPardonForm(void) { return; }

PresidentialPardonForm::PresidentialPardonForm(std::string name, int gradeExec, int gradeSigned) :
    AForm("president request",name, gradeExec, gradeSigned) { return ;}

PresidentialPardonForm::PresidentialPardonForm(std::string name) :
    AForm("president request", name, 5, 25) { return ;}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & rhs) {
    *this = rhs;
    return;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getGradeExe())
        throw AForm::GradeTooLowException();
    std::cout << this->getName() << " as been pardoned by Zafod Beeblebrox." << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
    if (this != &rhs) {
        this->setIsSigned(rhs.getIsSigned());
    }
    return *this;
}