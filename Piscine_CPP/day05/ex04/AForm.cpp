#include "AForm.hpp"

AForm::AForm(void) : _name(""), _target(""), _gradeExe(1), _gradeSigned(1), _isSigned(false) { return; }

AForm::~AForm(void) { return; }

AForm::AForm(std::string name, std::string target, int gradeExe, int gradeSigned) : _name(name), _target(target),_gradeExe(gradeExe), _gradeSigned(gradeSigned), _isSigned(false) {
    if (this->getGradeExe() > 150 || this->getGradeSigned() > 150) throw GradeTooLowException();
    if (this->getGradeExe() < 1 || this->getGradeSigned() < 1) throw GradeTooHighException();
    return;
}

AForm::AForm(AForm const & rhs) : _name(rhs.getName()), _target(rhs.getTarget()), _gradeExe(rhs.getGradeExe()), _gradeSigned(rhs.getGradeSigned()) {
    this->_isSigned = rhs.getIsSigned();
    return;
}

std::string AForm::getName(void) const {
    return this->_name;
}

std::string AForm::getTarget(void) const {
    return this->_target;
}

void AForm::signedForm(void) {
    if (this->_isSigned)
        throw AForm::AlreadySigned();
    this->_isSigned = true;
}

bool AForm::getIsSigned(void) const {
    return this->_isSigned;
}

int AForm::getGradeSigned(void) const {
    return this->_gradeSigned;
}

int AForm::getGradeExe(void) const {
    return this->_gradeExe;
}

void AForm::setIsSigned(bool isSigned) {
    this->_isSigned = isSigned;
    return;
}

AForm & AForm::operator=(AForm const & rhs)  {
    if (this != &rhs) {
        this->_isSigned = rhs.getIsSigned();
    }
    return *this;
}

void AForm::beSigned(Bureaucrat const & src) const{
    if (src.getGrade() > this->getGradeSigned())
        throw GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, AForm const & rhs) {
    o << rhs.getName() << ", form grade < grade executed :"
        << rhs.getGradeExe() << ", grade signed :"
        << rhs.getGradeSigned() << ">"
        << " targeted on " << rhs.getTarget()
        << ((rhs.getIsSigned()) ? std::string("(Signed)") : std::string("(Unsigned)"));
    return o;
}

AForm::GradeTooLowException::GradeTooLowException(void) { return; }

AForm::GradeTooLowException::~GradeTooLowException(void) throw() { return; }

AForm::GradeTooLowException::GradeTooLowException(GradeTooLowException const & rhs) {
    *this = rhs;
    return;
}

const char* AForm::GradeTooLowException::what(void) const throw() {
    return(" Too low grade grade ");
}

AForm::GradeTooLowException & AForm::GradeTooLowException::operator=(GradeTooLowException const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}

AForm::GradeTooHighException::GradeTooHighException(void) { return; }

AForm::GradeTooHighException::~GradeTooHighException(void) throw() { return; }

const char* AForm::GradeTooHighException::what(void) const throw() {
    return(" Too high grade grade ");
}

AForm::GradeTooHighException::GradeTooHighException(GradeTooHighException const & rhs) {
    *this = rhs;
    return;
}

AForm::GradeTooHighException & AForm::GradeTooHighException::operator=(GradeTooHighException const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}

AForm::NotSignedException::NotSignedException(void) { return; }

AForm::NotSignedException::~NotSignedException(void) throw() { return; }

const char* AForm::NotSignedException::what(void) const throw() {
    return(" Form not singed");
}

AForm::NotSignedException::NotSignedException(NotSignedException const & rhs) {
    *this = rhs;
    return;
}

AForm::NotSignedException & AForm::NotSignedException::operator=(NotSignedException const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}

AForm::AlreadySigned::AlreadySigned(void) { return; }

AForm::AlreadySigned::~AlreadySigned(void) throw() { return; }

const char* AForm::AlreadySigned::what(void) const throw() {
    return(" already signed");
}

AForm::AlreadySigned::AlreadySigned(AlreadySigned const & rhs) {
    *this = rhs;
    return;
}

AForm::AlreadySigned & AForm::AlreadySigned::operator=(AlreadySigned const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}