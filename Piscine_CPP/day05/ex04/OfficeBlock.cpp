#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void) : _intern(NULL), _signer(NULL), _executor(NULL) { return; }

OfficeBlock::OfficeBlock(Intern & intern, Bureaucrat & signer, Bureaucrat & executor)
    : _intern(&intern), _signer(&signer), _executor(&executor) { return; }

OfficeBlock::~OfficeBlock(void) { return; }

OfficeBlock::OfficeBlock(OfficeBlock const & rhs) {
    *this = rhs;
    return;
}

OfficeBlock & OfficeBlock::operator=(OfficeBlock const & rhs) {
    if (this != &rhs) {
        this->setExecutor(*rhs.getExecutor());
        this->setSigner(*rhs.getSigner());
        this->setIntern(*rhs.getIntern());
    }
    return *this;
}

void OfficeBlock::setIntern(Intern & rhs) {
    this->_intern = &rhs;
}

void OfficeBlock::setSigner(Bureaucrat & rhs) {
    this->_signer = &rhs;
}

void OfficeBlock::setExecutor(Bureaucrat & rhs) {
    this->_executor = &rhs;
}

Intern* OfficeBlock::getIntern(void) const {
    return this->_intern;
}

Bureaucrat* OfficeBlock::getSigner(void) const {
    return this->_signer;
}

Bureaucrat* OfficeBlock::getExecutor(void) const {
    return this->_executor;
}

void OfficeBlock::doBureaucracy(std::string const form, std::string const target) {
    if (!this->getExecutor())
        throw OfficeBlock::ExecutorEmpty();
    if (!this->getSigner())
        throw OfficeBlock::SignerEmpty();
    if (!this->getIntern())
        throw OfficeBlock::InternEmpty();
    AForm * rff = this->_intern->makeForm(form, target);
    this->_signer->signForm(*rff);
    this->_executor->executeForm(*rff);
    return;
}

OfficeBlock::SignerEmpty::SignerEmpty(void) { return; }

OfficeBlock::SignerEmpty::~SignerEmpty(void) throw() { return; }

const char* OfficeBlock::SignerEmpty::what(void) const throw() {
    return(" empty signer");
}

OfficeBlock::SignerEmpty::SignerEmpty(SignerEmpty const & rhs) {
    *this = rhs;
    return;
}

OfficeBlock::SignerEmpty & OfficeBlock::SignerEmpty::operator=(SignerEmpty const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}

OfficeBlock::ExecutorEmpty::ExecutorEmpty(void) { return; }

OfficeBlock::ExecutorEmpty::~ExecutorEmpty(void) throw() { return; }

const char* OfficeBlock::ExecutorEmpty::what(void) const throw() {
    return(" empty executor");
}

OfficeBlock::ExecutorEmpty::ExecutorEmpty(ExecutorEmpty const & rhs) {
    *this = rhs;
    return;
}

OfficeBlock::ExecutorEmpty & OfficeBlock::ExecutorEmpty::operator=(ExecutorEmpty const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}

OfficeBlock::InternEmpty::InternEmpty(void) { return; }

OfficeBlock::InternEmpty::~InternEmpty(void) throw() { return; }

const char* OfficeBlock::InternEmpty::what(void) const throw() {
    return(" empty intern");
}

OfficeBlock::InternEmpty::InternEmpty(InternEmpty const & rhs) {
    *this = rhs;
    return;
}

OfficeBlock::InternEmpty & OfficeBlock::InternEmpty::operator=(InternEmpty const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}