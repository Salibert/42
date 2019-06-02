#include "Bureaucrat.hpp"
#include "Form.hpp"
int main() {
    Form order66 = Form("order66", 1, 66);
    Bureaucrat hamza = Bureaucrat("Hamza", 150);
    Bureaucrat palpatine = Bureaucrat("Palpatine", 1);
    std::cout << hamza << std::endl;
    hamza.signForm(order66);
    std::cout << order66 << std::endl;
    std::cout << palpatine << std::endl;
    palpatine.signForm(order66);
    std::cout << order66 << std::endl;
    palpatine.signForm(order66);
    return 0;
}