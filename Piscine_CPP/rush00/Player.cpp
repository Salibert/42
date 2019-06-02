#include "Player.hpp"

Player::Player(void) : GameEntities::GameEntities(1, 0, "A", NULL, GameEntities::Position(), GameEntities::Speed()) {
    this->_Position.x = GameEntities::MAX_X / 2;
    this->_Position.y = GameEntities::MAX_Y - 5;
    this->_Speed.x = 1;
    this->_Speed.y = 0;
    this->setWeapon(new PlayerWeapon());
    return;
}
Player::~Player() {
    return;
}

Player::Player(int hp, int score, std::string shape, AWeapon *weapon, Position position, Speed speed)
    : GameEntities::GameEntities(hp, score, shape, weapon, position, speed) {
	return;
}

Player::Player( Player const &player) {
	*this = player;
    return;
}

Player &Player::operator=(Player const & right) {
    (void) right;
	return *this;
}

void Player::setTotalScore(unsigned int amount) {
    this->_totalScore += amount;
    return;
}

unsigned int Player::getTotalScore(void) {
    return this->_totalScore;
}

bool Player::checkCollision(GameEntities const &gameEntity) {
	if (this->_Position.x == gameEntity.getPosition().x || this->_Position.x == gameEntity.getPosition().x + 1
	|| this->_Position.x == gameEntity.getPosition().x + 2 || this->_Position.x == gameEntity.getPosition().x + 3)
	    return (this->_Position.y == gameEntity.getPosition().y);
	return false;
}

void Player::shoot(List *allies) const {
    GameEntities::Speed speed;
    speed.x = 0;
    speed.y = -2;
    GameEntities *rocket = new Player(1, 0, "!", new AlienWeapon(), this->getPosition(), speed);
    allies->createNode(rocket);
}

unsigned int Player::_totalScore = 0;