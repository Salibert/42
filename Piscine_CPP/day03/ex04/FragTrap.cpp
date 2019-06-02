#include "FragTrap.hpp"

/* forbidden constructor */

FragTrap::FragTrap(void) : ClapTrap() {
    this->set_Armor_damage_reduction(5);
    this->set_Energy_points(100);
    this->set_Hit_points(100);
    this->set_level(1);
    this->set_Max_energy_points(100);
    this->set_Max_hit_points(100);
    this->set_Melee_attack_damage(30);
    this->set_Ranged_attack_damage(20);
    this->_list_attack[0] = &FragTrap::superFlang;
    this->_list_attack[1] = &FragTrap::boomburst;
    this->_list_attack[2] = &FragTrap::miniTail;
    this->_list_attack[3] = &FragTrap::eggBomb;
    this->_list_attack[4] = &FragTrap::yawn;
    std::cout << this->get_name() << " it's connecting" << std::endl;
    return ;
}

/* constructor */

FragTrap::FragTrap(std::string const & name) : ClapTrap(name) {
        this->set_Armor_damage_reduction(5);
        this->set_Energy_points(100);
        this->set_Hit_points(100);
        this->set_level(1);
        this->set_Max_energy_points(100);
        this->set_Max_hit_points(100);
        this->set_Melee_attack_damage(30);
        this->set_Ranged_attack_damage(20);
        this->_list_attack[0] = &FragTrap::superFlang;
        this->_list_attack[1] = &FragTrap::boomburst;
        this->_list_attack[2] = &FragTrap::miniTail;
        this->_list_attack[3] = &FragTrap::eggBomb;
        this->_list_attack[4] = &FragTrap::yawn;
        std::cout << this->get_name() << " it's connecting" << std::endl;
        return;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)  {
        std::cout << this->get_name() << " it's connecting by cpy" << std::endl;
        return;
}

/* destructor */

FragTrap::~FragTrap(void) {
    std::cout << this->get_name() << " it's disconnecting" << std::endl;
    return ;
}


/* Members functions*/


void FragTrap::rangedAttack(std::string const & target) {
    std::cout << "FragTrap " << this->_name << " attacks " << target
        << " at range , causing " << this->_Ranged_attack_damage
        << " points of damage !" << std::endl;
    return;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
    if (this->get_Energy_points() >= 25 ) {
        (this->*(_list_attack[rand() % 5]))(target);
        this->set_Energy_points(this->get_Energy_points() - 25);
    } else
        std::cout << this->get_name() << ": I don't have enough energy" << std::endl;
}

void FragTrap::superFlang(std::string const & target) {
    std::cout << this->get_name() << " attacks " << target << " with ";
    std::cout << " super fang" << std::endl;
    return;
}

void FragTrap::miniTail(std::string const & target) {
    std::cout << this->get_name() << " attacks " << target << " with ";
    std::cout << " miniTail" << std::endl;
    return;
}

void FragTrap::eggBomb(std::string const & target) {
    std::cout << this->get_name() << " attacks " << target << " with ";
    std::cout << " eggBomb " << std::endl;
    return;
}

void FragTrap::yawn(std::string const & target) {
    std::cout << this->get_name() << " attacks " << target << " with ";
    std::cout << " yawn " << std::endl;
    return;
}

void FragTrap::boomburst(std::string const & target) {
    std::cout << this->get_name() << " attacks " << target << " with ";
    std::cout << " boomburst " << std::endl;
    return;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs) {
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