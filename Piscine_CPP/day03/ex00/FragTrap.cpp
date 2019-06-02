#include "FragTrap.hpp"

/* forbidden constructor */

FragTrap::FragTrap(void) { return ;}

/* constructor */

FragTrap::FragTrap(std::string const & name) :
    _name(name),
    _level(1),
    _Hit_points(100),
    _Energy_points(100),
    _Max_hit_points(100),
    _Max_energy_points(100),
    _Melee_attack_damage(30),
    _Ranged_attack_damage(20),
    _Armor_damage_reduction(5) {
        this->_list_attack[0] = &FragTrap::superFlang;
        this->_list_attack[1] = &FragTrap::boomburst;
        this->_list_attack[2] = &FragTrap::miniTail;
        this->_list_attack[3] = &FragTrap::eggBomb;
        this->_list_attack[4] = &FragTrap::yawn;
        std::cout << this->_name << " it's connecting" << std::endl;
        return;
    }

FragTrap::FragTrap(FragTrap const & src) {
        *this = src;
        std::cout << this->_name << " it's connecting by cpy" << std::endl;
        return;
}

/* destructor */

FragTrap::~FragTrap(void) {
    std::cout << this->_name << " it's disconnecting" << std::endl;
    return ;
}


/* Members functions*/

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
    if (this->_Energy_points >= 25 ) {
        (this->*(_list_attack[rand() % 5]))(target);
        this->set_Energy_points(this->_Energy_points - 25);
    } else
        std::cout << this->_name << ": I don't have enough energy" << std::endl;
}

void FragTrap::rangedAttack(std::string const & target) {
    std::cout << "FRA4G-TP " << this->_name << " attacks " << target;
    std::cout << " at range , causing " << this->_Ranged_attack_damage;
    std::cout << " points of damage !" << std::endl;
    return;
}

void FragTrap::meleeAttack(std::string const & target) {
    std::cout << "FRA4G-TP " << this->_name << " attacks "  << target;
    std::cout << " at melee , causing " << this->_Melee_attack_damage;
    std::cout << " points of damage !" << std::endl;
    return;
}

void FragTrap::superFlang(std::string const & target) {
    std::cout << this->_name << " attacks " << target << " with ";
    std::cout << " super fang" << std::endl;
    return;
}

void FragTrap::miniTail(std::string const & target) {
    std::cout << this->_name << " attacks " << target << " with ";
    std::cout << " miniTail" << std::endl;
    return;
}

void FragTrap::eggBomb(std::string const & target) {
    std::cout << this->_name << " attacks " << target << " with ";
    std::cout << " eggBomb " << std::endl;
    return;
}

void FragTrap::yawn(std::string const & target) {
    std::cout << this->_name << " attacks " << target << " with ";
    std::cout << " yawn " << std::endl;
    return;
}

void FragTrap::boomburst(std::string const & target) {
    std::cout << this->_name << " attacks " << target << " with ";
    std::cout << " boomburst " << std::endl;
    return;
}


void FragTrap::takeDamage(unsigned int amount) {
    if (this->_Hit_points == 0) {
        std::cout << "To steal is useless, " << this->_name <<" is already dead" << std::endl;
        return;
    }
    if (amount > this->_Armor_damage_reduction) {
        amount -= this->_Armor_damage_reduction;
        this->set_Hit_points(amount > this->_Hit_points ? 0 : this->_Hit_points - amount);
        if (this->_Hit_points == 0)
            std::cout << "OH NONNNNN ! " << this->_name << " is died " << std::endl;
        else
            std::cout << this->_name << " lost " << amount << " ! He still has " << this->_Hit_points << " hp !" << std::endl;
    } else
        std::cout << this->_name << " dodged the attack" << std::endl;
    return;
}

void FragTrap::beRepaired(unsigned int amount) {
    amount += this->_Hit_points;
    amount = amount < this->_Max_hit_points ? amount : this->_Max_hit_points;
    this->set_Hit_points(amount);
    std::cout << this->_name << " be repaired to " << amount << "! He still has " << this->_Hit_points << " hp !" << std::endl;
    return;
}

/* GET */

int FragTrap::get_Hit_points(void) const {
    return this->_Hit_points;
}

int FragTrap::get_Max_hit_points(void) const {
    return this->_Max_energy_points;
}

int FragTrap::get_Energy_points(void) const {
    return this->_Energy_points;
}

int FragTrap::get_Max_energy_points(void) const {
    return this->_Max_energy_points;
}

int FragTrap::get_level(void) const {
    return this->_level;
}

int FragTrap::get_Melee_attack_damage(void) const {
    return this->_Melee_attack_damage;
}

int FragTrap::get_Ranged_attack_damage(void) const {
    return this->_Ranged_attack_damage;
}

int FragTrap::get_Armor_damage_reduction(void) const {
    return this->_Armor_damage_reduction;
}

std::string FragTrap::get_name(void) const {
    return this->_name;
}

/* Set */
void FragTrap::set_Hit_points(unsigned int const hp) {
    this->_Hit_points = hp;
    return;
}

void FragTrap::set_Max_hit_points(unsigned int const max_hit_p) {
    this->_Max_hit_points = max_hit_p;
    return;
}

void FragTrap::set_Energy_points(unsigned int const energie_p) {
    this->_Energy_points = energie_p;
    return;
}

void FragTrap::set_Max_energy_points(unsigned int const max_energie_p) {
    this->_Max_energy_points = max_energie_p;
    return;
}

void FragTrap::set_level(unsigned int const level) {
    this->_level = level;
    return;
}

void FragTrap::set_Melee_attack_damage(unsigned int const attack_damage) {
    this->_Melee_attack_damage = attack_damage;
    return;
}

void FragTrap::set_Ranged_attack_damage(unsigned int const attack_damage) {
    this->_Ranged_attack_damage = attack_damage;
    return;
}

void FragTrap::set_Armor_damage_reduction(unsigned int const damage_red) {
    this->_Armor_damage_reduction = damage_red;
    return;
}

void FragTrap::set_name(std::string const & name) {
    this->_name = name;
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