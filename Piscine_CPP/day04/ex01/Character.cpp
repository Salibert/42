# include "Character.hpp"

Character::Character(void) {return ;}

Character::Character(std::string const & name) : _name(name), _AP(40), _weapon(NULL) { return ;}

int Character::getAP(void) const { return this->_AP; }

void Character::setAP(int amount) {
    this->_AP = amount;    
}

AWeapon* Character::getWeapon(void) const { return this->_weapon; }

void Character::recoverAP(void) {
    if ((this->getAP() + 10) < 40 )
        this->setAP(this->getAP() + 10);
    else
        this->setAP(40);
    return;
}

void Character::equip(AWeapon *weapon) {
    this->_weapon = weapon;
    return;
}

std::string Character::getName(void) const { return this->_name; }

void Character::attack(Enemy* enemy) {
    if (!this->_weapon)
        std::cout << this->getName() << " is not equipped to fight, he runs away." << std::endl;
    else if (!enemy)
        std::cout << this->getName() << " is not equipped to fight, he runs away." << std::endl;
    else {
        if (this->getAP() < this->_weapon->getAPCost())
            std::cout << "Sorry " << this->getName() << " ! but you don't have any more AP for this attack" << std::endl;
        else if (enemy->getHitPoint() == 0)
            std::cout << "Sorry " << this->getName() << " ! but he's already dead" << std::endl;
        else {
            this->_weapon->attack();
            enemy->takeDamage(this->_weapon->getDamage());
            std::cout << this->getName() << " attack " << enemy->getType()
            <<  " with " << this->_weapon->getName()
            << " and impose " << this->_weapon->getDamage() << " to damage !" << std::endl
            << enemy->getType() << " only has " << enemy->getHitPoint() << std::endl;
            this->_AP -= this->_weapon->getAPCost();
        }
    }
    return;
}

Character::~Character(void) {return ;}

Character & Character::operator=(Character const & rhs) {
    if (this != &rhs) {
        this->_AP = rhs.getAP();
        this->_name = rhs.getName();
        this->_weapon = rhs.getWeapon();
    }
    return *this;
}

std::ostream & operator<<(std::ostream & o, Character const & rhs) {
    if (rhs.getWeapon())
        o << rhs.getName() << " has " << rhs.getAP() << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
    else
        o << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed" << std::endl;
    return o;
}