#include "FragTrap.hpp"

int main() {
    FragTrap billy = FragTrap("Billy");
    FragTrap bob = FragTrap("Bob");

    billy.meleeAttack("Bob");
    bob.takeDamage(billy.get_Melee_attack_damage());
    billy.rangedAttack("Bob");
    bob.takeDamage(billy.get_Ranged_attack_damage());
    bob.beRepaired(1000);
    std::cout << "Bob is full life " << bob.get_Hit_points() << std::endl;
    bob.vaulthunter_dot_exe("Billy");
    billy.takeDamage(30);
    bob.vaulthunter_dot_exe("Billy");
    billy.takeDamage(100);
    bob.vaulthunter_dot_exe("Billy");
    billy.takeDamage(100);
    bob.vaulthunter_dot_exe("Billy");
    billy.takeDamage(100);
    bob.vaulthunter_dot_exe("Billy");
    return 0;
}