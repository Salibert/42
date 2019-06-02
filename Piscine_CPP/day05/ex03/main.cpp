#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    Bureaucrat wahiba = Bureaucrat("Wahiba", 150);
    Bureaucrat paul = Bureaucrat("Paul", 45);
    Bureaucrat tree = Bureaucrat("tree", 1);
    Intern someRandomIntern;
    AForm* rrf;
    try {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        tree.signForm(*rrf);
        paul.executeForm(*rrf);
        paul.executeForm(*rrf);
        paul.executeForm(*rrf);
        paul.executeForm(*rrf);
        delete rrf;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    try {
        rrf = someRandomIntern.makeForm("president request", "BILLYKILLER");
        tree.signForm(*rrf);
        wahiba.executeForm(*rrf);
        tree.executeForm(*rrf);
        delete rrf;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    try {
        rrf = someRandomIntern.makeForm("shrubbery request", "SAVE TREE");
        wahiba.signForm(*rrf);
        paul.executeForm(*rrf);
        paul.signForm(*rrf);
        paul.executeForm(*rrf);
        delete rrf;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try {
        rrf = someRandomIntern.makeForm("Not Exit request", "SAVE TREE");
        wahiba.signForm(*rrf);
        paul.executeForm(*rrf);
        paul.signForm(*rrf);
        paul.executeForm(*rrf);
        delete rrf;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}