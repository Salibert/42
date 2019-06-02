#include "OfficeBlock.hpp"

int main() {
    Bureaucrat wahiba = Bureaucrat("Wahiba", 150);
    Bureaucrat paul = Bureaucrat("Paul", 25);
    Bureaucrat tree = Bureaucrat("tree", 1);
    Intern idiotOne;
    OfficeBlock ob;
    
    try {
        ob.doBureaucracy("president request", "Bender");
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "set executor " << tree.getName() << std::endl;
    ob.setExecutor(tree);
    try {
        ob.doBureaucracy("president request", "Bender");
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "set signer " << paul.getName() << std::endl;
    ob.setSigner(paul);
    try {
        ob.doBureaucracy("president request", "Bender");
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "set intern idiotOne " << std::endl;
    ob.setIntern(idiotOne);
    try {
        ob.doBureaucracy("president request", "Bender");
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    OfficeBlock ob2(idiotOne, wahiba, tree);
    try {
        ob2.doBureaucracy("shrubbery request", "BILLY");
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}