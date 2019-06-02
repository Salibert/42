#include "SuperTrap.hpp"

int main() {

    NinjaTrap bob = NinjaTrap("Bob");
    ClapTrap marko = ClapTrap("Marko");
    FragTrap didier = FragTrap("Didier");
    ScavTrap kevin = ScavTrap("Kevin");
    SuperTrap c17 = SuperTrap("C-17");

    std::cout << " ========== CLAPTRAP ========="  << std::string( 3, '\n' );
    c17.meleeAttack("Marko");
    marko.takeDamage(bob.get_Melee_attack_damage());
    c17.rangedAttack("Marko");
    marko.takeDamage(bob.get_Ranged_attack_damage());

    std::cout << std::string( 2, '\n' ) << " ========== NINJATRAP ========="  << std::string( 3, '\n' );
    c17.meleeAttack("billy");
    c17.rangedAttack("billy");
    c17.ninjaShoebox(marko);
    c17.ninjaShoebox(didier);
    c17.ninjaShoebox(kevin);

    std::cout << std::string( 2, '\n' ) << " ========== FRAGTRAP ========="  << std::string( 3, '\n' );

    std::cout << "C-17 is full life " << c17.get_Hit_points() << std::endl;
    c17.vaulthunter_dot_exe("Bob");
    bob.takeDamage(50);
    didier.vaulthunter_dot_exe("C-17");
    c17.takeDamage(1);

    std::cout << std::string( 3, '\n' );
    return 0;
}