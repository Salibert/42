#include "Intern.hpp"

Intern::Intern(void) { return ; }

Intern::Intern(Intern const & rhs) { (void)rhs; return; }

Intern::~Intern(void) { return; }

AForm * Intern::makeForm(std::string const & request, std::string const & target) {
        if(request == std::string("robotomy request"))
            return new RobotomyRequestForm(target);
        if(request.c_str() == std::string("president request"))
            return new PresidentialPardonForm(target);
        if(request.c_str() == std::string("shrubbery request"))
            return new ShrubberyCreationForm(target);
        throw Intern::NotExitRequest();
    return NULL;
}

Intern & Intern::operator=(Intern const & rhs) {
    (void)rhs;
    return *this;
}

Intern::NotExitRequest::NotExitRequest(void) { return; }

Intern::NotExitRequest::~NotExitRequest(void) throw() { return; }

const char* Intern::NotExitRequest::what(void) const throw() {
    return(" this request does not exist");
}

Intern::NotExitRequest::NotExitRequest(NotExitRequest const & rhs) {
    *this = rhs;
    return;
}

Intern::NotExitRequest & Intern::NotExitRequest::operator=(NotExitRequest const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}