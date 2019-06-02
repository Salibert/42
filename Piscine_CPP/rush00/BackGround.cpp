#include "BackGround.hpp"

BackGround::BackGround(void) : GameEntities::GameEntities(1000000, 10, "*", NULL, GameEntities::Position(), GameEntities::Speed()) {
    this->_Position.y = (rand() % GameEntities::MAX_Y - 4) + 1;
    this->_Position.x = (rand() % GameEntities::MAX_X - 1) + 1;
    return;
}
BackGround::~BackGround() {
    return;
}

BackGround::BackGround(int hp, int score, std::string shape, AWeapon *weapon, Position position, Speed speed)
        : GameEntities::GameEntities(hp, score, shape, weapon, position, speed) {
	return;
}

BackGround::BackGround( BackGround const &enemy) {
	*this = enemy;
    return;
}

void BackGround::move(void) {
    if (this->getPosition().y > GameEntities::MAX_Y) {
        this->_Position.x = (rand() % GameEntities::MAX_X - 1) + 1;
        this->_Position.y = 0;
    } else {
        this->_Position.y += 1;
    }
}

void BackGround::print(WINDOW * win) {
    if (this->getPosition().y < GameEntities::MAX_Y - 2 && this->getPosition().y > 0) {
        wattron(win, COLOR_PAIR(4) | A_BOLD );
        mvwprintw(win, this->getPosition().y, this->getPosition().x, "*");
        wattroff(win, COLOR_PAIR(4) | A_BOLD);
    }
}

BackGround &BackGround::operator=(BackGround const & right) {
    (void) right;
	return *this;
}
