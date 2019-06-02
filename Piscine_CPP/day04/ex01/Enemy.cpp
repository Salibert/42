#include "Enemy.hpp"

Enemy::~Enemy(void) { return; }

Enemy::Enemy(void) { return; }

Enemy::Enemy(int hp, std::string const & type) : _type(type), _HitPoint(hp) { return; }

Enemy::Enemy(Enemy const & rhs) { *this = rhs; return; }

std::string Enemy::getType(void) const { return this->_type;  }

int Enemy::getHitPoint(void) const { return this->_HitPoint;  }
void Enemy::deathDisplay(void) const { return; }
void Enemy::takeDamage(int amount) {
    if (this->getHitPoint() && (this->getHitPoint() - amount) <= 0)
        this->deathDisplay();
    if (amount <= this->getHitPoint())
        this->_HitPoint -= amount;
    else
        this->_HitPoint = 0;
    return;
}

Enemy & Enemy::operator=(Enemy const & rhs) {
    if (this != &rhs) {
        this->_HitPoint = rhs.getHitPoint();
        this->_type = rhs.getType();
    }
    return *this;
}
