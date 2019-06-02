#include "executioner.hpp"

Executioner::Executioner(void) {
	this->op["add"] = &Executioner::add;
	this->op["pop"] = &Executioner::pop;
	this->op["sub"] = &Executioner::sub;
	this->op["mul"] = &Executioner::mul;
	this->op["div"] = &Executioner::div;
	this->op["mod"] = &Executioner::mod;
	this->op["pow"] = &Executioner::power;
	this->op["dump"] = &Executioner::dump;
	this->op["exit"] = &Executioner::exitE;
	this->op["print"] = &Executioner::print;
	return;
}

Executioner::Executioner(Executioner const &src)  {
	(void)(src);
	return;
}

Executioner &Executioner::operator=(Executioner const & src) {
	(void)(src);
	return *this;
}

Executioner::~Executioner(void) { return; }

void Executioner::startVm(Parser *parse) {
	std::list<VM_List>::const_iterator start;
	eOperandType enumId = eOperandType::enum_double;
	
	for (start = parse->vmList.begin(); start != parse->end; ++start)
	{
		if (start->type != "null") { enumId = this->getEnumId(start->type); }
		if (start->info == "push") { this->push(enumId,start->value); }
		if (start->info == "assert") { this->assertE(enumId, start->value); }
		if (start->info == "while") { this->whileE(this->getLast(),start->value); }
		it = this->op.find(start->info);
		if (it != this->op.end()) {
			(this->*(op[start->info]))();
		}
	}
}

eOperandType Executioner::getEnumId(std:: string type) {
	if (type == "int8") {
		return eOperandType::enum_int8;
	} else if (type == "int16") {
		return eOperandType::enum_int16;
	} else if (type == "int32") {
		return eOperandType::enum_int32;
	} else if (type == "float") {
		return eOperandType::enum_float;
	} else {
		return eOperandType::enum_double;
	}
}

/* OPERATION  */

void Executioner::add() {
	if (this->stack.size() < 2) {
		throw ErrorControler::ExecutionerStack();
	} else {
		this->stack.push_back(*this->getLastAndPop() + *this->getLastAndPop());
	}
}

void Executioner::sub() {
	if (this->stack.size() < 2) {
		throw ErrorControler::ExecutionerStack();
	} else {
		this->stack.push_back(*this->getLastAndPop() - *this->getLastAndPop());
	}
}

void Executioner::mul() {
	if (this->stack.size() < 2) {
		throw ErrorControler::ExecutionerStack();
	} else {
		this->stack.push_back(*this->getLastAndPop() * *this->getLastAndPop());
	}
}

void Executioner::div() {

	if (this->stack.size() < 2) {
		throw ErrorControler::ExecutionerStack();
	} else {
		IOperand const * rhs = this->getLastAndPop();
		IOperand const * lhs = this->getLastAndPop();
		if (std::stod(rhs->toString()) == static_cast<double>(0)) {
			throw ErrorControler::ExecutionerModOrDivZero();
		} else {
			this->stack.push_back(*lhs / *rhs);
		}
	}
}

void Executioner::mod(){
	if (this->stack.size() < 2) {
		throw ErrorControler::ExecutionerStack();
	} else {
		IOperand const * rhs = this->getLastAndPop();
		IOperand const * lhs = this->getLastAndPop();
		if (std::stod(rhs->toString()) == static_cast<double>(0)) {
			throw ErrorControler::ExecutionerModOrDivZero();
		} else {
			this->stack.push_back(*lhs % *rhs);
		}
	}
}

void Executioner::power() {
  	if (this->stack.size() < 2) {
		throw ErrorControler::ExecutionerStack();
	} else {
		this->stack.push_back(*this->getLastAndPop() ^ *this->getLastAndPop());
	}
}
/* END OPERATION */

void Executioner::whileE(IOperand const *last, std::string const & value) {
	if (this->stack.size() == 0) {
		throw ErrorControler::ExecutionerStackEmpty();
	} else {
		int i = stod(value);
		while (i--) {
			this->stack.push_back(last);
		}
	}
}

void Executioner::push(eOperandType enumId, std::string const & value) {
	this->stack.push_back(factory.createOperand(enumId, value));
}

void Executioner::assertE(eOperandType enumId, std::string const & value) {
  	if (this->stack.size() == 0) {
		throw ErrorControler::ExecutionerStackEmpty();
	} else {
		IOperand const * last =  this->getLast();
		IOperand const * tmp = factory.createOperand(enumId, value);
		if (last->toString() != tmp->toString() || last->getType() != tmp->getType()) {
			throw std::logic_error("Error on the assert");
		} else {
			this->stack.push_back(tmp);
		}
	}
}

void Executioner::pop() {
	if (this->stack.size() == 0) {
		throw ErrorControler::ExecutionerStackEmpty();
	} else {
		this->stack.pop_back();
	}
}

void Executioner::dump() {
	if (this->stack.size() == 0) {
		throw ErrorControler::ExecutionerStackEmpty();
	} else {
		std::list<IOperand const *>:: iterator end = this->stack.end();
		end--;
		std::cout << "\033[1;33mDump: \033[0m" << std::endl;
		while (end != this->stack.begin()) {
			std::cout << "\033[1;36m"<<(*end)->toString() << "\033[0m" << std::endl;
			end--;
		}
		std::cout << "\033[1;36m" << this->stack.front()->toString() << "\033[0m" << std::endl;
	}
}

IOperand const *Executioner::getLast() {
	return this->stack.back();
}

IOperand const  *Executioner::getLastAndPop() {
	IOperand const * tmp = this->stack.back();
	this->stack.pop_back();
	return tmp;
}

void Executioner::print() {
  	if (this->stack.size() == 0) {
		throw ErrorControler::ExecutionerStackEmpty();
	} else {
  		IOperand const * lhs = this->getLast();
  		if (lhs->getType()!= 0) {
			throw std::logic_error("impossible to print this elements");
		} else {
  			int value = std::stoi(lhs->toString());
			if (value < 0) {
				throw std::logic_error("impossible to print this negatif elements");
			} else {
				std::cout << static_cast<char>(value) << std::endl;
			}
		}
	}
}

void Executioner::exitE() {
  std::cout << "\033[1;32mBye Bye \033[0m" << std::endl;
  std::exit(0);
}
