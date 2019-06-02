#include "ScavTrap.hpp"

/* forbidden constructor */

ScavTrap::ScavTrap(void) { return ;}

/* constructor */

ScavTrap::ScavTrap(std::string const & name) :
    _name(name),
    _level(1),
    _Hit_points(100),
    _Energy_points(50),
    _Max_hit_points(100),
    _Max_energy_points(50),
    _Melee_attack_damage(20),
    _Ranged_attack_damage(15),
    _Armor_damage_reduction(3) {
        this->_list_attack[0] = &ScavTrap::challenge1;
        this->_list_attack[1] = &ScavTrap::challenge2;
        this->_list_attack[2] = &ScavTrap::challenge3;
        this->_list_attack[3] = &ScavTrap::challenge4;
        this->_list_attack[4] = &ScavTrap::challenge5;
        std::cout << this->_name << " joined the party" << std::endl;
        return;
    }

ScavTrap::ScavTrap(ScavTrap const & src) {
        *this = src;
        std::cout << this->_name << " joined the party by cpy" << std::endl;
        return;
}

/* destructor */

ScavTrap::~ScavTrap(void) {
    std::cout << this->_name << " left the party" << std::endl;
    return ;
}


/* Members functions*/

void ScavTrap::challengeNewcomer(std::string const & target) {
    if (this->_Energy_points >= 25 ) {
        (this->*(_list_attack[rand() % 5]))(target);
        this->set_Energy_points(this->_Energy_points - 25);
    } else
        std::cout << this->_name << ": I don't have enough energy" << std::endl;
}

void ScavTrap::rangedAttack(std::string const & target) {
    std::cout << "Scav-TP " << this->_name << " attacks " << target;
    std::cout << " at range , causing " << this->_Ranged_attack_damage;
    std::cout << " points of damage !" << std::endl;
    return;
}

void ScavTrap::meleeAttack(std::string const & target) {
    std::cout << "Scav-TP " << this->_name << " attacks "  << target;
    std::cout << " at melee , causing " << this->_Melee_attack_damage;
    std::cout << " points of damage !" << std::endl;
    return;
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


void ScavTrap::takeDamage(unsigned int amount) {
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

void ScavTrap::beRepaired(unsigned int amount) {
    amount += this->_Hit_points;
    amount = amount < this->_Max_hit_points ? amount : this->_Max_hit_points;
    this->set_Hit_points(amount);
    std::cout << this->_name << " be repaired to " << amount << "! He still has " << this->_Hit_points << " hp !" << std::endl;
    return;
}

/* GET */

int ScavTrap::get_Hit_points(void) const {
    return this->_Hit_points;
}

int ScavTrap::get_Max_hit_points(void) const {
    return this->_Max_energy_points;
}

int ScavTrap::get_Energy_points(void) const {
    return this->_Energy_points;
}

int ScavTrap::get_Max_energy_points(void) const {
    return this->_Max_energy_points;
}

int ScavTrap::get_level(void) const {
    return this->_level;
}

int ScavTrap::get_Melee_attack_damage(void) const {
    return this->_Melee_attack_damage;
}

int ScavTrap::get_Ranged_attack_damage(void) const {
    return this->_Ranged_attack_damage;
}

int ScavTrap::get_Armor_damage_reduction(void) const {
    return this->_Armor_damage_reduction;
}

std::string ScavTrap::get_name(void) const {
    return this->_name;
}

/* Set */
void ScavTrap::set_Hit_points(unsigned int const hp) {
    this->_Hit_points = hp;
    return;
}

void ScavTrap::set_Max_hit_points(unsigned int const max_hit_p) {
    this->_Max_hit_points = max_hit_p;
    return;
}

void ScavTrap::set_Energy_points(unsigned int const energie_p) {
    this->_Energy_points = energie_p;
    return;
}

void ScavTrap::set_Max_energy_points(unsigned int const max_energie_p) {
    this->_Max_energy_points = max_energie_p;
    return;
}

void ScavTrap::set_level(unsigned int const level) {
    this->_level = level;
    return;
}

void ScavTrap::set_Melee_attack_damage(unsigned int const attack_damage) {
    this->_Melee_attack_damage = attack_damage;
    return;
}

void ScavTrap::set_Ranged_attack_damage(unsigned int const attack_damage) {
    this->_Ranged_attack_damage = attack_damage;
    return;
}

void ScavTrap::set_Armor_damage_reduction(unsigned int const damage_red) {
    this->_Armor_damage_reduction = damage_red;
    return;
}

void ScavTrap::set_name(std::string const & name) {
    this->_name = name;
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