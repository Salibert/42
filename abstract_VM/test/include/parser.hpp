# ifndef PARSER_HPP
# define PARSER_HPP

#include <string>
#include <list>

#include <iostream>
#include <sstream>
#include <regex>
#include <limits>

struct VM_List {
	std::string info;
	std::string type;
	std::string value;
};

class Parser {
	public:
		std::list<VM_List> vmList;
		std::list<VM_List>::const_iterator start;
		std::list<VM_List>::const_iterator end;

		Parser(void);
		Parser(Parser const &src); // Copy
		virtual ~Parser(void); // Destructeur de recopie

		Parser &operator=(Parser const & src);  // operator d'affecationt

		int check(std::string & instrucion);
		int lexer(std::string & instrucion);
		void push(std::string instrucion);
		int getIndexLine(void) const;
		bool exit;

  	private:
	  	static std::regex regexContent;
    	int _indexLine;
};

#endif
