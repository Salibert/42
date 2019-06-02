#include "Bureaucrat.hpp"

int main() {
    for (int i=0; i < 3; i++) {
        try {
            Bureaucrat hamza = Bureaucrat("Hamza", i * 75);
            std::cout << hamza << std::endl;
        } catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::string(2,'\n');
    try {
        Bureaucrat Billy = Bureaucrat("billy", 1);
        std::cout << Billy << std::endl
        << Billy.getName() << " incrementGrade" << std::endl;
        Billy.incrementGrade();
        std::cout << Billy << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::string(2,'\n');
    try {
        Bureaucrat Billy = Bureaucrat("billy", 1);
        std::cout << Billy << std::endl
        << Billy.getName() << " decrementGrade" << std::endl;
        Billy.decrementGrade();
        std::cout << Billy << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::string(2,'\n');
    try {
        Bureaucrat Billy = Bureaucrat("billy", 150);
        std::cout << Billy << std::endl
        << Billy.getName() << " decrementGrade" << std::endl;
        Billy.decrementGrade();
        std::cout << Billy << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::string(2,'\n');
    try {
        Bureaucrat Billy = Bureaucrat("billy", 150);
        std::cout << Billy << std::endl
        << Billy.getName() << " incrementGrade" << std::endl;
        Billy.incrementGrade();
        std::cout << Billy << std::endl;
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}