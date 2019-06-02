# ifndef ERRORCONTROLER_HPP
# define ERRORCONTROLER_HPP

#include "parser.hpp"
#include "IOperand.hpp"
#include <math.h>
#include <stdexcept>

#define END_OF_FILE "You must have an exit at the end of instructions"
#define MOD_OR_DIV_BY_0 "impossible mod or div by 0"
#define SYNTAX_ERROR "Syntax error on this instruction: "
#define EXIT_ERROR "Exit must be the last instruction: "
#define FALSE_INST_ERROR "This instruction is false: "
#define ERROR_STACK_2_EL "\033[1;31m You need at least 2 elements on your stack to do this operation \033[0m"
#define ERROR_U_FLOW "You have an underflow"
#define ERROR_O_FLOW "You have an overflow"
#define ERROR_EMPTY_STACK "You can't do that on a empty stack"

enum eOperator { ADD = 0, MUL = 1, SUB = 2, DIV = 3, POW = 4, MOD = 5 };

class ErrorControler {
	public:
		class ExecutionerStack : public std::exception {
			public:
				ExecutionerStack(void);
				virtual ~ExecutionerStack(void) throw();
				ExecutionerStack(ExecutionerStack const & rhs);
				ExecutionerStack & operator=(ExecutionerStack const & rhs);
				virtual const char* what() const throw();
		};
		class EndOfFile : public std::exception {
			public:
				EndOfFile(void);
				virtual ~EndOfFile(void) throw();
				EndOfFile(EndOfFile const & rhs);
				EndOfFile & operator=(EndOfFile const & rhs);
				virtual const char* what() const throw();
		};
		class ExecutionerModOrDivZero : public std::exception {
			public:
				ExecutionerModOrDivZero(void);
				virtual ~ExecutionerModOrDivZero(void) throw();
				ExecutionerModOrDivZero(ExecutionerModOrDivZero const & rhs);
				ExecutionerModOrDivZero & operator=(ExecutionerModOrDivZero const & rhs);
				virtual const char* what() const throw();
		};

		class ExecutionerStackEmpty : public std::exception {
			public:
				ExecutionerStackEmpty(void);
				virtual ~ExecutionerStackEmpty(void) throw();
				ExecutionerStackEmpty(ExecutionerStackEmpty const & rhs);
				ExecutionerStackEmpty & operator=(ExecutionerStackEmpty const & rhs);
				virtual const char* what() const throw();
		};

		ErrorControler(void);
		ErrorControler(ErrorControler const &src);
		virtual ~ErrorControler(void);
		
		ErrorControler &operator=(ErrorControler const & src);
		int needToStopFd(int type, bool isExit, std::string nextValue, bool fd, int line);
		int needToStopCin(int type, bool isExit, std::string nextValue, int line);
		void endofFile(bool isExit);
		static void overflow(IOperand const *operan, IOperand const *operan1, eOperator operatorType);
		static void underflow(IOperand const *operan, IOperand const *operan1, eOperator operatorType);
		bool exit;

	private:
		class OperatorOverflow : public std::exception {
			public:
				OperatorOverflow(void);
				virtual ~OperatorOverflow(void) throw();
				OperatorOverflow(OperatorOverflow const & rhs);
				OperatorOverflow & operator=(OperatorOverflow const & rhs);
				virtual const char* what() const throw();
		};
		class OperatorUnderflow : public std::exception {
			public:
				OperatorUnderflow(void);
				virtual ~OperatorUnderflow(void) throw();
				OperatorUnderflow(OperatorUnderflow const & rhs);
				OperatorUnderflow & operator=(OperatorUnderflow const & rhs);
				virtual const char* what() const throw();
		};
		int putError(int line, std::string const & error) const;
};

#endif
