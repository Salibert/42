# ifndef EXECUTIONER_HPP
# define EXECUTIONER_HPP

#include <string>
#include <list>
#include <map>
#include <iostream>
#include <sstream>
#include <regex>
#include "parser.hpp"
#include "operatorControler.hpp"
#include "IOperand.hpp"
#include "operatorFactory.hpp"
#include "errorControler.hpp"

class Executioner {
	typedef void (Executioner::*Func)(void);
	public:
		Executioner(void);
		Executioner(Executioner const &src);
		virtual ~Executioner(void);

		Executioner &operator=(Executioner const & src);
		void startVm(Parser *parse);
	private:
		std::map<std::string, Func> op;
		std::map<std::string, Func>::iterator it;
		std::list<IOperand const *> stack;
		std::list<IOperand const *>::const_iterator start;
		std::list<IOperand const *>::const_iterator end;

		eOperandType getEnumId(std:: string type);
		IOperand const * getLast(void);
		IOperand const * getLastAndPop(void);
		void push(eOperandType enumId, std::string const & value);
		void assertE(eOperandType enumId, std::string const & value);
		void add(void);
		void power(void);
		void sub(void);
		void mul(void);
		void div(void);
		void mod(void);
		void print(void);
		void pop(void);
		void dump(void);
		void exitE(void);
		void whileE(IOperand const *last, std::string const & value);
		OperatorFactory factory;
};

#endif
