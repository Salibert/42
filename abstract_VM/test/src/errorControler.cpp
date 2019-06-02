#include "errorControler.hpp"

ErrorControler::ErrorControler(void){
  return;
}

ErrorControler::ErrorControler(ErrorControler const &src) {
  (void)(src);
  return;
}

ErrorControler &ErrorControler::operator=(ErrorControler const & src) {
  (void)(src);
  return *this;
}

ErrorControler::~ErrorControler(void) { return; }

int ErrorControler::needToStopFd(int type, bool isExit, std::string nextValue, bool fd, int line) {
  	if (type == 1 && fd != 0) {
		return this->putError(line, SYNTAX_ERROR);
  	} else if (isExit && nextValue != "") {
		return this->putError(line,EXIT_ERROR);
  	} else if (type == 3) {
		return this->putError(line,FALSE_INST_ERROR);
	}
	return 0;
}

int ErrorControler::needToStopCin(int type, bool isExit, std::string nextValue, int line) {
	if (type == 1) {
		return this->putError(line,SYNTAX_ERROR);
	} else  if (isExit && nextValue != "") {
		return this->putError(line,EXIT_ERROR);
	} else if (type == 3) {
		return this->putError(line,FALSE_INST_ERROR);
	}
	return 0;
}

void ErrorControler::endofFile(bool isExit) {
  	if (isExit) {
		throw EndOfFile();
  	}
}

int ErrorControler::putError(int line, std::string const & error) const {
  std::cerr << "\033[1;31mLine\033[0m " <<"\033[1;32m" << line << "\033[0m" << "\033[1;31m : " << error <<"\033[0m" << std::endl;
  return 1;
}

void ErrorControler::overflow(IOperand const *operan,  IOperand const *operan1, eOperator operatorType) {
	long double max = (operan->getPrecision() > operan1->getPrecision()) ? operan->getMax() : operan1->getMax();
	switch (operatorType) {
		case ADD :
			if (std::stod(operan->toString()) + std::stod(operan1->toString()) > max) {
				throw OperatorOverflow();
			} else {
				return;
			}
		case MUL :
			if (std::stod(operan->toString()) * std::stod(operan1->toString()) > max) {
				throw OperatorOverflow();
			} else {
				return;
			}
		case SUB:
			if (std::stod(operan->toString()) - std::stod(operan1->toString()) > max) {
				throw OperatorOverflow();
			} else {
				return;
			}
		case POW:
			if (pow(std::stod(operan1->toString()),std::stod(operan->toString())) > max) {
				throw OperatorOverflow();
			} else {
				return;
			}
		default:
			return;
	}
}

void ErrorControler::underflow(IOperand const *operan,  IOperand const *operan1, eOperator operatorType) {
	long double min = (operan->getPrecision() > operan1->getPrecision()) ? operan->getMin() : operan1->getMin();
	switch (operatorType) {
		case ADD :
			if (std::stod(operan->toString()) + std::stod(operan1->toString()) < min) {
				throw OperatorUnderflow();
			} else {
				return;
			}
		case MUL :
			if (std::stod(operan->toString()) * std::stod(operan1->toString()) < min) {
				throw OperatorUnderflow();
			} else {
				return;
			}
		case SUB:
			if (std::stod(operan->toString()) - std::stod(operan1->toString()) < min) {
				throw OperatorUnderflow();
			} else {
				return;
			}
		case POW:
			if (pow(std::stod(operan1->toString()),std::stod(operan->toString())) < min) {
				throw OperatorUnderflow();
			} else {
				return;
			}
		default:
			return;
	}
}

ErrorControler::OperatorOverflow::OperatorOverflow(void) { return; }

ErrorControler::OperatorOverflow::~OperatorOverflow(void) throw() { return; }

ErrorControler::OperatorOverflow::OperatorOverflow(OperatorOverflow const & rhs) {
    *this = rhs;
    return;
}

const char* ErrorControler::OperatorOverflow::what(void) const throw() { return(ERROR_O_FLOW); }

ErrorControler::OperatorOverflow & ErrorControler::OperatorOverflow::operator=(OperatorOverflow const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}

ErrorControler::OperatorUnderflow::OperatorUnderflow(void) { return; }

ErrorControler::OperatorUnderflow::~OperatorUnderflow(void) throw() { return; }

ErrorControler::OperatorUnderflow::OperatorUnderflow(OperatorUnderflow const & rhs) {
    *this = rhs;
    return;
}

const char* ErrorControler::OperatorUnderflow::what(void) const throw() { return(ERROR_U_FLOW); }

ErrorControler::OperatorUnderflow & ErrorControler::OperatorUnderflow::operator=(OperatorUnderflow const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}

ErrorControler::ExecutionerStack::ExecutionerStack(void) { return; }

ErrorControler::ExecutionerStack::~ExecutionerStack(void) throw() { return; }

ErrorControler::ExecutionerStack::ExecutionerStack(ExecutionerStack const & rhs) {
    *this = rhs;
    return;
}

const char* ErrorControler::ExecutionerStack::what(void) const throw() { return(ERROR_STACK_2_EL); }

ErrorControler::ExecutionerStack & ErrorControler::ExecutionerStack::operator=(ExecutionerStack const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}

ErrorControler::ExecutionerModOrDivZero::ExecutionerModOrDivZero(void) { return; }

ErrorControler::ExecutionerModOrDivZero::~ExecutionerModOrDivZero(void) throw() { return; }

ErrorControler::ExecutionerModOrDivZero::ExecutionerModOrDivZero(ExecutionerModOrDivZero const & rhs) {
    *this = rhs;
    return;
}

const char* ErrorControler::ExecutionerModOrDivZero::what(void) const throw() { return(MOD_OR_DIV_BY_0); }

ErrorControler::ExecutionerModOrDivZero & ErrorControler::ExecutionerModOrDivZero::operator=(ExecutionerModOrDivZero const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}

ErrorControler::EndOfFile::EndOfFile(void) { return; }

ErrorControler::EndOfFile::~EndOfFile(void) throw() { return; }

ErrorControler::EndOfFile::EndOfFile(EndOfFile const & rhs) {
    *this = rhs;
    return;
}

const char* ErrorControler::EndOfFile::what(void) const throw() { return(END_OF_FILE); }

ErrorControler::EndOfFile & ErrorControler::EndOfFile::operator=(EndOfFile const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}

ErrorControler::ExecutionerStackEmpty::ExecutionerStackEmpty(void) { return; }

ErrorControler::ExecutionerStackEmpty::~ExecutionerStackEmpty(void) throw() { return; }

ErrorControler::ExecutionerStackEmpty::ExecutionerStackEmpty(ExecutionerStackEmpty const & rhs) {
    *this = rhs;
    return;
}

const char* ErrorControler::ExecutionerStackEmpty::what(void) const throw() { return(ERROR_EMPTY_STACK); }

ErrorControler::ExecutionerStackEmpty & ErrorControler::ExecutionerStackEmpty::operator=(ExecutionerStackEmpty const & rhs) {
    (std::exception)*this = std::exception::operator=(rhs);
    return *this;
}