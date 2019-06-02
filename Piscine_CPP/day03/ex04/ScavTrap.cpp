#include "ScavTrap.hpp"

/* forbidden constructor */

ScavTrap::ScavTrap(void) : ClapTrap() {
    this->set_Armor_damage_reduction(3);
    this->set_Energy_points(50);
    this->set_Hit_points(100);
    this->set_level(1);
    this->set_Max_energy_points(50);
    this->set_Max_hit_points(100);
    this->set_Melee_attack_damage(20);
    this->set_Ranged_attack_damage(15);
    this->_list_attack[0] = &ScavTrap::challenge1;
    this->_list_attack[1] = &ScavTrap::challenge2;
    this->_list_attack[2] = &ScavTrap::challenge3;
    this->_list_attack[3] = &ScavTrap::challenge4;
    this->_list_attack[4] = &ScavTrap::challenge5;
    std::cout << this->get_name() << " joined the party" << std::endl;    
    return ;
}

/* constructor */

ScavTrap::ScavTrap(std::string const & name) : ClapTrap(name) {
        this->set_Armor_damage_reduction(3);
        this->set_Energy_points(50);
        this->set_Hit_points(100);
        this->set_level(1);
        this->set_Max_energy_points(50);
        this->set_Max_hit_points(100);
        this->set_Melee_attack_damage(20);
        this->set_Ranged_attack_damage(15);
        this->_list_attack[0] = &ScavTrap::challenge1;
        this->_list_attack[1] = &ScavTrap::challenge2;
        this->_list_attack[2] = &ScavTrap::challenge3;
        this->_list_attack[3] = &ScavTrap::challenge4;
        this->_list_attack[4] = &ScavTrap::challenge5;
        std::cout << this->get_name() << " joined the party" << std::endl;
        return;
    }

ScavTrap::ScavTrap(ScavTrap const & src) {
        *this = src;
        std::cout << this->get_name() << " joined the party by cpy" << std::endl;
        return;
}

/* destructor */

ScavTrap::~ScavTrap(void) {
    std::cout << this->get_name() << " left the party" << std::endl;
    return ;
}


/* Members functions*/

void ScavTrap::challengeNewcomer(std::string const & target) {
    if (this->get_Energy_points() >= 25 ) {
        (this->*(_list_attack[rand() % 5]))(target);
        this->set_Energy_points(this->get_Energy_points() - 25);
    } else
        std::cout << this->get_name() << ": I don't have enough energy" << std::endl;
}

void ScavTrap::challenge1(std::string const & target) {
    std::cout << target <<" Mimic a cult movie scene" << std::endl;
    return;
}

void ScavTrap::challenge2(std::string const & target) {
    std::cout << target << " brush the teeth of another player" << std::endl;
    return;
}

void ScavTrap::challenge3(std::string const & target) {
    std::cout << target << " walk from one end of the room to the other while squinting" << std::endl;
    return;
}

void ScavTrap::challenge4(std::string const & target) {
    std::cout << target << " sing a song bawdy" << std::endl;
    return;
}

void ScavTrap::challenge5(std::string const & target) {
    std::cout << target << " draw self portrait with blindfold" << std::endl;
    return;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
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