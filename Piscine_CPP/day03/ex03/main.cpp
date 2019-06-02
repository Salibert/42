#include "NinjaTrap.hpp"

int main() {

    NinjaTrap bob = NinjaTrap("Bob");
    ClapTrap marko = ClapTrap("Marko");
    FragTrap didier = FragTrap("Didier");
    ScavTrap kevin = ScavTrap("Kevin");
    NinjaTrap billy = NinjaTrap("Billy");

    bob.meleeAttack("Marko");
    marko.takeDamage(bob.get_Melee_attack_damage());
    marko.rangedAttack("bob");
    bob.takeDamage(marko.get_Ranged_attack_damage());
    
    std::cout << std::endl;
    bob.ninjaShoebox(marko);
    bob.ninjaShoebox(didier);
    bob.ninjaShoebox(kevin);
    bob.ninjaShoebox(billy);
    std::cout << std::endl;

    return 0;
}