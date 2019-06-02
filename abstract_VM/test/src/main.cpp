#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <fcntl.h>

#include "parser.hpp"
#include "errorControler.hpp"
#include "executioner.hpp"

int main (int argc, char **argv) {

	Parser *parse = new Parser();
	ErrorControler error;
	Executioner exec;
	int stop = 0;
	std::string nextValue = "";

	if (argc >= 2) {
		try {
			std::string value;
			std::ifstream fd;
			fd.open(argv[1]);
			if(!fd.is_open()) {
				std::cout <<"\033[1;33mI can't open this type of file !!\033[0m\n";
				return 0;
			}
			while (!fd.eof()) {
				std::getline(fd,value);
				if (parse->exit) {
					nextValue = value;
				}
				if ((error.needToStopFd(parse->check(value), parse->exit, nextValue, !fd.eof(), parse->getIndexLine()) == 1 ||
					error.needToStopFd(parse->lexer(value), parse->exit, nextValue, !fd.eof(), parse->getIndexLine()) == 1) &&
					!fd.eof() != 0) {
					std::cout <<"\033[1;33m" << value << "\033[0m\n";
					stop = 1;
				}
			}
			if (stop == 1) {
				fd.close();
				return 0;
			}
			error.endofFile(!parse->exit);

			fd.close();
			exec.startVm(parse);
		} catch ( const std::exception & e ) { std::cerr << "\033[1;33m" << e.what() << "\033[0m\n"; }
	} else {
		try {
			std::string line;
			while (true) {
				std::getline(std::cin, line);
				if (";;" == line || std::cin.eof() == 1) {
					if (!parse->exit) { throw std::logic_error( "you miss exit"); }
					break;
				} else {
					if (parse->exit) {
						nextValue = line;
					}
					if ((error.needToStopCin(parse->check(line), parse->exit, nextValue, parse->getIndexLine()) == 1 ||
						error.needToStopCin(parse->lexer(line), parse->exit, nextValue, parse->getIndexLine()) == 1)) {
						std::cout << line << std::endl;
						return 0;
					}
				}
			}
			exec.startVm(parse);
		} catch (const std::exception & e) { std::cerr << e.what(); }
	}
	return 0;
}
