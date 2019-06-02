#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) { return; }

Bureaucrat::~Bureaucrat(void) { return; }

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
    this->setGrade(this->getGrade());
    return;
}

Bureaucrat::Bureaucrat(Bureaucrat const & rhs) {
    *this = rhs;
    return;
}

void Bureaucrat::setGrade(int grade) {
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
        this->_grade = grade;
}

void Bureaucrat::incrementGrade(void) {
    if (this->getGrade() == 1)
        throw GradeTooHighException();
    else
        this->_grade -= 1;
}

void Bureaucrat::decrementGrade(void) {
    if (this->getGrade() == 150)
        throw GradeTooLowException();
    else
        this->_grade += 1;
}

std::string Bureaucrat::getName(void) const {
    return this->_name;
}

int Bureaucrat::getGrade(void) const {
    return this->_grade;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {
    if (this != &rhs) {
        *this = Bureaucrat(rhs.getName(), rhs.getGrade());
    }
    return *this;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs) {
    o << rhs.getName() << ", bureaucrat grade <" << rhs.getGrade() << ">";
    return o;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) { return; }

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() { return; }

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const & rhs) {
    *this = rhs;
    return;
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
    return("Lowest grade reached");
}

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}


Bureaucrat::GradeTooHighException::GradeTooHighException(void) { return; }

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() { return; }

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
    return("Highest grade reached");
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const & rhs) {
    *this = rhs;
    return;
}

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}