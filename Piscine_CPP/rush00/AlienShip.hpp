#ifndef ALIENSHIP_HPP
# define ALIENSHIP_HPP

# include "PlayerWeapon.hpp"
# include "Enemy.hpp"

class AlienShip : public Enemy
{
    protected:
        AlienShip(AlienShip const &AlienShip);
    public:
        AlienShip(int hp, int score, std::string shape, AWeapon *weapon, Position position, Speed speed);
        AlienShip(void);
        virtual ~AlienShip();
        AlienShip &operator=(AlienShip const &AlienShip);
};

#endif