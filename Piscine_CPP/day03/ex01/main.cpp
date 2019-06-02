#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap billy = ScavTrap("Billy");
    ScavTrap bob = ScavTrap("Bob");
    billy.meleeAttack("Bob");
    bob.takeDamage(billy.get_Melee_attack_damage());
    billy.rangedAttack("Bob");
    bob.takeDamage(billy.get_Ranged_attack_damage());
    bob.beRepaired(1000);
    std::cout << "Bob is full life " << bob.get_Hit_points() << std::endl;
    bob.challengeNewcomer("Billy");
    std::cout << billy.get_name() << " execute challenge with success" << std::endl;
    billy.challengeNewcomer("Bob");
    std::cout << bob.get_name() << " failed challenge" << std::endl;
    bob.takeDamage(100);
    billy.challengeNewcomer("Billy");
    std::cout << bob.get_name() << " execute challenge with success" << std::endl;
    bob.beRepaired(1000);;
    bob.challengeNewcomer("Billy");
    std::cout << bob.get_name() << " epic failed challenge" << std::endl;
    billy.takeDamage(1000);
    return 0;
}