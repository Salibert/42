#ifndef GAMEENTITIES_HPP
# define GAMEENTITIES_HPP

# include <string>
# include <iostream>
#include "AWeapon.hpp"
#include <ncurses.h>

class GameEntities
{
    protected:
        int _score;
    public:
        struct Position {
            int x;
            int y;
        };
        struct Speed{
            int x;
            int y;
        };
        int _Hp;
        std::string _Shape;
        AWeapon *_Weapon;
        Speed _Speed;
        Position _Position;

        static int MAX_X, MAX_Y;

        GameEntities(int hp, int _score, std::string shape, AWeapon *weapon, Position position, Speed speed);
        GameEntities(GameEntities const &GameEntities);
        GameEntities();
        virtual ~GameEntities();

        int getHp() const;
        int getScore() const;
        std::string getShape() const;
        Position getPosition() const;
        Speed getSpeed() const;
        AWeapon* getWeapon() const;
        void setWeapon(AWeapon* weapon);
        void setHp(int amount);
        GameEntities &operator=(GameEntities const & GameEntities);
        virtual void takeDamage(int damage);
        virtual bool checkCollision(GameEntities const &gameEntity);
        void print(WINDOW * win) const;
        virtual unsigned int getTotalScore(void);
        virtual void setTotalScore(unsigned int amount);
        void move(int x, int y);

};

#endif