#include "SuperTrap.hpp"

/* forbidden constructor */

SuperTrap::SuperTrap(void) :  FragTrap(), NinjaTrap() {
    return ;
}

/* constructor */

SuperTrap::SuperTrap(std::string const & name) : ClapTrap(name), FragTrap(name), NinjaTrap(name){
        FragTrap default_frag(name);
        this->set_Armor_damage_reduction(default_frag.get_Armor_damage_reduction());
        this->set_Energy_points(this->get_Energy_points());
        this->set_Hit_points(default_frag.get_Hit_points());
        this->set_level(1);
        this->set_Max_energy_points(this->get_Max_energy_points());
        this->set_Max_hit_points(default_frag.get_Max_hit_points());
        this->set_Melee_attack_damage(this->get_Melee_attack_damage());
        this->set_Ranged_attack_damage(default_frag.get_Ranged_attack_damage());
        std::cout << this->get_name() << " SUPERTRAPER is comming" << std::endl;
        return;
}

SuperTrap::SuperTrap(SuperTrap const & src) : ClapTrap(src)  {
        std::cout << this->get_name() << " SUPERTRAPER is comming" << std::endl;
        return;
}

/* destructor */

SuperTrap::~SuperTrap(void) {
    std::cout << this->get_name() << " SUPERTRAPER is missing" << std::endl;
    return ;
}


/* Members functions*/

void SuperTrap::meleeAttack(std::string const & target) {
    this->NinjaTrap::meleeAttack(target);
    return;
}

void SuperTrap::rangedAttack(std::string const & target) {
    this->FragTrap::rangedAttack(target);
    return;
}

SuperTrap & SuperTrap::operator=(SuperTrap const & rhs) {
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