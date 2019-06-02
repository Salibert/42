#include "AlienShip.hpp"

AlienShip::AlienShip(void) : Enemy::Enemy(100, 10, "Q", NULL, GameEntities::Position(), GameEntities::Speed()) {
    this->_Speed.x = 0;
    this->_Speed.y = 1;
    this->_Position.x = (rand() % (GameEntities::MAX_X - 4)) + 4;
    this->_Position.y = -10;
    this->setWeapon(new PlayerWeapon());
    return;
}
AlienShip::~AlienShip(void) {
    return;
}

AlienShip::AlienShip(int hp, int score, std::string shape, AWeapon *weapon, Position position, Speed speed)
    : Enemy::Enemy(hp, score, shape, weapon, position, speed) {
    this->_Speed.x = 0;
    this->_Speed.y = 1;
    this->_Position.x = (rand() % (GameEntities::MAX_X - 4)) + 4;
    this->_Position.y = -10;
    this->setWeapon(new PlayerWeapon());
	return;
}

AlienShip::AlienShip( AlienShip const &AlienShip) {
	*this = AlienShip;
    return;
}

AlienShip &AlienShip::operator=(AlienShip const & right) {
    (void) right;
	return *this;
}