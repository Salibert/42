#ifndef BACKGROUND_HPP
# define BACKGROUND_HPP

# include "GameEntities.hpp"

class BackGround : public GameEntities
{
    protected:
        BackGround(BackGround const &BackGround);
        BackGround(int hp, int score, std::string shape, AWeapon *weapon, Position position, Speed speed);
    public:
        BackGround(void);
        virtual ~BackGround();
        void move(void);
        BackGround &operator=(BackGround const &BackGround);

        virtual void print(WINDOW *win);

};

#endif