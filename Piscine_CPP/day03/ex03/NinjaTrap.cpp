#include "NinjaTrap.hpp"

/* forbidden constructor */

NinjaTrap::NinjaTrap(void) : ClapTrap() { return ;}

/* constructor */

NinjaTrap::NinjaTrap(std::string const & name) : ClapTrap(name) {
        this->set_Armor_damage_reduction(0);
        this->set_Energy_points(120);
        this->set_Hit_points(60);
        this->set_level(1);
        this->set_Max_energy_points(120);
        this->set_Max_hit_points(60);
        this->set_Melee_attack_damage(60);
        this->set_Ranged_attack_damage(5);
        std::cout << this->get_name() << " is invoke" << std::endl;
        return;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) : ClapTrap(src)  {
        std::cout << this->get_name() << " is invoke by cpy" << std::endl;
        return;
}

/* destructor */

NinjaTrap::~NinjaTrap(void) {
    std::cout << this->get_name() << " is dispel" << std::endl;
    return ;
}


/* Members functions*/

void NinjaTrap::ninjaShoebox(ClapTrap const & rhs) const {
    std::cout << this->get_name() << " attack " << rhs.get_name() << " with neck breeze" << std::endl;
    return;
}

void NinjaTrap::ninjaShoebox(FragTrap const & rhs) const {
    std::cout << this->get_name() << " attack " << rhs.get_name() << " with elbow breeze" << std::endl;
    return;
}

void NinjaTrap::ninjaShoebox(NinjaTrap const & rhs) const {
    std::cout << this->get_name() << " no attack " << rhs.get_name() << " because it's my friend !" << std::endl;
    return;
}

void NinjaTrap::ninjaShoebox(ScavTrap const & rhs) const {
    std::cout << this->get_name() << " attack " << rhs.get_name() << " with body breeze" << std::endl;
    return;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & rhs) {
    if (this != &rhs) {
        this->set_Armor_damage_reduction(rhs.get_Armor_damage_reduction());
        this->set_Energy_points(rhs.get_Energy_points());
        this->set_Hit_points(rhs.get_Hit_points());
        this->set_level(rhs.get_level());
        this->set_Max_energy_points(rhs.get_Max_energy_points());
        this->set_Max_hit_points(rhs.get_Max_hit_points());
        this->set_Melee_attack_damage(rhs.get_Melee_attack_damage());
        this->set_Ranged_attack_damage(rhs.get_Ranged_attack_damage());
        this->set_name(rhs.get_name());
    }
    return *this;
}