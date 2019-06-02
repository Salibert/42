#include "ClapTrap.hpp"

/* forbidden constructor */

ClapTrap::ClapTrap(void) :
    _level(1),
    _Hit_points(100),
    _Energy_points(100),
    _Max_hit_points(100),
    _Max_energy_points(100),
    _Melee_attack_damage(30),
    _Ranged_attack_damage(20),
    _Armor_damage_reduction(5) {
    std::stringstream sstm;
    sstm << "Player" << ClapTrap::_nb_players;
    this->_name = sstm.str();
    ClapTrap::_nb_players += 1;
    return;
}

/* constructor */

ClapTrap::ClapTrap(std::string const & name) :
    _name(name),
    _level(1),
    _Hit_points(100),
    _Energy_points(100),
    _Max_hit_points(100),
    _Max_energy_points(100),
    _Melee_attack_damage(30),
    _Ranged_attack_damage(20),
    _Armor_damage_reduction(5) {
        std::cout << this->_name << " try to connect " << std::endl;
        return;
    }

ClapTrap::ClapTrap(ClapTrap const & src) {
        *this = src;
        std::cout << this->_name << " try to connect by cpy" << std::endl;
        return;
}

/* destructor */

ClapTrap::~ClapTrap(void) {
    std::cout << this->_name << " section game expired" << std::endl;
    return ;
}

/* Members functions*/

void ClapTrap::rangedAttack(std::string const & target) {
    std::cout << "FRA4G-TP " << this->_name << " attacks " << target
        << " at range , causing " << this->_Ranged_attack_damage
        << " points of damage !" << std::endl;
    return;
}

void ClapTrap::meleeAttack(std::string const & target) {
    std::cout << "FRA4G-TP " << this->_name << " attacks "  << target
        << " at melee , causing " << this->_Melee_attack_damage
        << " points of damage !" << std::endl;
    return;
}

void ClapTrap::takeDamage(unsigned int amount) {
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

void ClapTrap::beRepaired(unsigned int amount) {
    amount += this->_Hit_points;
    amount = amount < this->_Max_hit_points ? amount : this->_Max_hit_points;
    this->set_Hit_points(amount);
    std::cout << this->_name << " be repaired to " << amount << "! He still has " << this->_Hit_points << " hp !" << std::endl;
    return;
}

/* GET */

int ClapTrap::get_Hit_points(void) const {
    return this->_Hit_points;
}

int ClapTrap::get_Max_hit_points(void) const {
    return this->_Max_energy_points;
}

int ClapTrap::get_Energy_points(void) const {
    return this->_Energy_points;
}

int ClapTrap::get_Max_energy_points(void) const {
    return this->_Max_energy_points;
}

int ClapTrap::get_level(void) const {
    return this->_level;
}

int ClapTrap::get_Melee_attack_damage(void) const {
    return this->_Melee_attack_damage;
}

int ClapTrap::get_Ranged_attack_damage(void) const {
    return this->_Ranged_attack_damage;
}

int ClapTrap::get_Armor_damage_reduction(void) const {
    return this->_Armor_damage_reduction;
}

std::string ClapTrap::get_name(void) const {
    return this->_name;
}

/* Set */
void ClapTrap::set_Hit_points(unsigned int const hp) {
    this->_Hit_points = hp;
    return;
}

void ClapTrap::set_Max_hit_points(unsigned int const max_hit_p) {
    this->_Max_hit_points = max_hit_p;
    return;
}

void ClapTrap::set_Energy_points(unsigned int const energie_p) {
    this->_Energy_points = energie_p;
    return;
}

void ClapTrap::set_Max_energy_points(unsigned int const max_energie_p) {
    this->_Max_energy_points = max_energie_p;
    return;
}

void ClapTrap::set_level(unsigned int const level) {
    this->_level = level;
    return;
}

void ClapTrap::set_Melee_attack_damage(unsigned int const attack_damage) {
    this->_Melee_attack_damage = attack_damage;
    return;
}

void ClapTrap::set_Ranged_attack_damage(unsigned int const attack_damage) {
    this->_Ranged_attack_damage = attack_damage;
    return;
}

void ClapTrap::set_Armor_damage_reduction(unsigned int const damage_red) {
    this->_Armor_damage_reduction = damage_red;
    return;
}

void ClapTrap::set_name(std::string const & name) {
    this->_name = name;
    return;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
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

unsigned int ClapTrap::_nb_players = 0;