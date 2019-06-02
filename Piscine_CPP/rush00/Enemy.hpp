#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "GameEntities.hpp"
# include "AlienWeapon.hpp"
# include "List.hpp"

class Enemy : public GameEntities
{
    protected:
        Enemy(void);
        Enemy(Enemy const &Enemy);
    public:
        Enemy(int hp, int score, std::string shape, AWeapon *weapon, Position position, Speed speed);
        virtual ~Enemy();
        Enemy &operator=(Enemy const &enemy);

        void shoot(List *enemies) const;

};

#endif