#include "Form.hpp"

Form::Form(void) : _name(""), _gradeExe(1), _gradeSigned(1), _isSigned(false) { return; }

Form::~Form(void) { return; }

Form::Form(std::string name, int gradeExe, int gradeSigned) : _name(name), _gradeExe(gradeExe), _gradeSigned(gradeSigned), _isSigned(false) {
    if (this->getGradeExe() > 150 || this->getGradeSigned() > 150) throw GradeTooLowException();
    if (this->getGradeExe() < 1 || this->getGradeSigned() < 1) throw GradeTooHighException();
    return;
}

Form::Form(Form const & rhs) : _name(rhs.getName()), _gradeExe(rhs.getGradeExe()), _gradeSigned(rhs.getGradeSigned()) {
    this->_isSigned = rhs.getIsSigned();
    return;
}

std::string Form::getName(void) const {
    return this->_name;
}

void Form::signedForm(void) {
    if (this->_isSigned)
        throw Form::AlreadySigned();
    this->_isSigned = true;
}

bool Form::getIsSigned(void) const {
    return this->_isSigned;
}

int Form::getGradeSigned(void) const {
    return this->_gradeSigned;
}

int Form::getGradeExe(void) const {
    return this->_gradeExe;
}

Form & Form::operator=(Form const & rhs) {
    if (this != &rhs) {
        *this = Form(rhs.getName(), rhs.getGradeExe(), rhs.getGradeSigned());
    }
    return *this;
}

void Form::beSigned(Bureaucrat const & src) const{
    if (src.getGrade() > this->getGradeSigned())
        throw GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, Form const & rhs) {
    o << rhs.getName() << ", form grade < grade executed :"
        << rhs.getGradeExe() << ", grade signed :"
        << rhs.getGradeSigned() << ">"
        << ((rhs.getIsSigned()) ? std::string(" form is signed") : std::string("form is not signed"));
    return o;
}

Form::GradeTooLowException::GradeTooLowException(void) { return; }

Form::GradeTooLowException::~GradeTooLowException(void) throw() { return; }

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & rhs) {
    *this = rhs;
    return;
}

const char* Form::GradeTooLowException::what(void) const throw() {
    return("Lowest grade reached");
}

Form::GradeTooLowException & Form::GradeTooLowException::operator=(GradeTooLowException const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}


Form::GradeTooHighException::GradeTooHighException(void) { return; }

Form::GradeTooHighException::~GradeTooHighException(void) throw() { return; }

const char* Form::GradeTooHighException::what(void) const throw() {
    return("Highest grade reached");
}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & rhs) {
    *this = rhs;
    return;
}

Form::GradeTooHighException & Form::GradeTooHighException::operator=(GradeTooHighException const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}

Form::AlreadySigned::AlreadySigned(void) { return; }

Form::AlreadySigned::~AlreadySigned(void) throw() { return; }

const char* Form::AlreadySigned::what(void) const throw() {
    return(" already signed");
}

Form::AlreadySigned::AlreadySigned(AlreadySigned const & rhs) {
    *this = rhs;
    return;
}

Form::AlreadySigned & Form::AlreadySigned::operator=(AlreadySigned const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}