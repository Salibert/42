#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "PlayerWeapon.hpp"
# include "AlienWeapon.hpp"
# include "List.hpp"

class Player : public GameEntities
{
    protected:
        static unsigned int _totalScore;
        Player(int hp, int score, std::string shape, AWeapon *weapon, Position position, Speed speed);
    public:

        Player(void);
        Player(Player const &Player);
        virtual ~Player(void);
        virtual unsigned int getTotalScore(void);
        virtual bool checkCollision(GameEntities const &gameEntity);
        virtual void setTotalScore(unsigned int amount);
        Player &operator=(Player const &player);

        void shoot(List *allies) const;
};

#endif