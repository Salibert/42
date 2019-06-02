#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    PresidentialPardonForm billyKiller = PresidentialPardonForm("BILLYKILLER");
    ShrubberyCreationForm ecosia = ShrubberyCreationForm("SAVE TREE");
    RobotomyRequestForm hamza = RobotomyRequestForm("Hamza");

    Bureaucrat wahiba = Bureaucrat("Wahiba", 150);
    Bureaucrat paul = Bureaucrat("Paul", 45);
    Bureaucrat tree = Bureaucrat("tree", 1);

    wahiba.signForm(ecosia);
    paul.executeForm(ecosia);
    paul.signForm(ecosia);
    paul.executeForm(ecosia);
    tree.signForm(hamza);
    paul.executeForm(hamza);
    paul.executeForm(hamza);
    paul.executeForm(hamza);
    paul.executeForm(hamza);
    tree.signForm(billyKiller);
    wahiba.executeForm(billyKiller);
    tree.executeForm(billyKiller);
    return 0;
}