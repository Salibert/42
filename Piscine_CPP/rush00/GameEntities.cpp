#include "GameEntities.hpp"

GameEntities::GameEntities(int hp, int score, std::string shape, AWeapon *weapon, Position position, Speed speed) :
	_score(score), _Hp(hp), _Shape(shape), _Weapon(weapon), _Speed(speed), _Position(position) {
    return ;
}

GameEntities::GameEntities() {
    return ;
}

GameEntities::GameEntities(GameEntities const & GameEntities)
{
	*this = GameEntities;
    return ;
}

GameEntities::~GameEntities() {
    if (this->_Weapon) {
        delete this->_Weapon;
        this->_Weapon = NULL;
    }
    return ;
}

GameEntities &GameEntities::operator=(GameEntities const & GameEntities)
{
	this->_Hp = GameEntities.getHp();
	this->_score = GameEntities.getScore();
	this->_Weapon = GameEntities.getWeapon();
	this->_Position = GameEntities.getPosition();
	this->_Speed = GameEntities.getSpeed();
	return *this;
}

int GameEntities::getHp() const {
    return this->_Hp;
}

void GameEntities::setHp(int amount) {
	this->_Hp = amount;
	if (this->_Shape == "3")
		this->_Shape = "2";
	else if (this->_Shape == "2")
		this->_Shape = "1";
	else if (this->_Shape == "2")
		this->_Shape = "1";
	return;
}

int GameEntities::getScore() const {
	return this->_score;
}

std::string GameEntities::getShape() const {
    return this->_Shape;
}

GameEntities::Position GameEntities::getPosition() const {
	return this->_Position;
}

GameEntities::Speed GameEntities::getSpeed() const {
	return this->_Speed;
}

AWeapon *GameEntities::getWeapon() const {
	return this->_Weapon;
}

void GameEntities::setWeapon(AWeapon* weapon) {
	this->_Weapon = weapon;
	return;
}

unsigned int GameEntities::getTotalScore(void) {
	return 0;
}

void GameEntities::setTotalScore(unsigned int amount) {
	(void) amount;
	return;
}

void GameEntities::takeDamage(int damage)
{
	if (damage >= 0)
	{
		if (this->_Hp <= damage)
			this->_Hp = 0;
		else
			this->_Hp -= damage;
	}

    return ;
}

bool GameEntities::checkCollision(GameEntities const &gameEntity) {
	if (this->getSpeed().y < 0 && this->_Position.x != gameEntity.getPosition().x && this->_Position.x != gameEntity.getPosition().x + 1
	&& this->_Position.x != gameEntity.getPosition().x + 2)
		return false;
	if (this->getSpeed().y > 0 && this->_Position.x != gameEntity.getPosition().x) 
		return false;
	return (this->getSpeed().y < 0) ? (this->_Position.y <= gameEntity.getPosition().y) : (this->_Position.y >= gameEntity.getPosition().y);
}

void GameEntities::move(int x, int y) {
	if (this->getShape() == "A") {
		if ((this->getPosition().x + x) > COLS - 5 || (this->getPosition().x + x) < 0 
		|| (this->getPosition().y + y) > LINES - 5 || (this->getPosition().y + y) < 0)
			return ;
	}
	this->_Position.x += x;
	this->_Position.y += y;
}

void GameEntities::print(WINDOW * win) const {
    if (this->getShape() == "!" || this->getShape() == "." || this->getShape() == "A")
    {
        if (this->getShape() == "!")
            wattron(win, COLOR_PAIR(3) | A_BOLD | A_UNDERLINE);
		else if (this->getShape() == "A")
			wattron(win, COLOR_PAIR(5) | A_BOLD | A_UNDERLINE);
        else
            wattron(win, COLOR_PAIR(2) | A_BOLD | A_UNDERLINE);
    }
    else if (this->getShape() != "." && this->getShape() != "!" && this->getShape() != "A")
    {
        if (this->getHp() == 1)
            wattron(win, COLOR_PAIR(2) | A_BOLD);
        if (this->getHp() == 2)
            wattron(win, COLOR_PAIR(1) | A_BOLD);
    }
    mvwprintw(win, this->getPosition().y, this->getPosition().x, this->getShape().c_str());
	if (this->getSpeed().y > 0) {
		mvwprintw(win, this->getPosition().y, this->getPosition().x + 1, this->getShape().c_str());
		mvwprintw(win, this->getPosition().y, this->getPosition().x + 2, this->getShape().c_str());
    }
    wattroff(win, COLOR_PAIR(1) | COLOR_PAIR(2) | COLOR_PAIR(3) | A_UNDERLINE | A_BOLD);
    return;
}

int GameEntities::MAX_Y = 0;
int GameEntities::MAX_X = 0;