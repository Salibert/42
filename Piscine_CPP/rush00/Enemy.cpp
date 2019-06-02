#include "Enemy.hpp"

Enemy::Enemy() {
    return;
}
Enemy::~Enemy() {
    return;
}

Enemy::Enemy(int hp, int score, std::string shape, AWeapon *weapon, Position position, Speed speed)
        : GameEntities::GameEntities(hp, score, shape, weapon, position, speed) {
	return;
}

Enemy::Enemy( Enemy const &enemy) {
	*this = enemy;
    return;
}

Enemy &Enemy::operator=(Enemy const & right) {
    (void) right;
	return *this;
}

void Enemy::shoot(List *enemies) const {
    GameEntities::Speed speed;
    speed.x = 0;
    speed.y = 2;
    GameEntities *rocket = new Enemy(1, 0, ".", new AlienWeapon(), this->getPosition(), speed);
    enemies->createNode(rocket);
}