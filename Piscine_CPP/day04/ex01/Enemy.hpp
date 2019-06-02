#ifndef ENEMY_H
# define ENEMY_H

# include <iostream>
class Enemy {
    protected:
        std::string _type;
        int _HitPoint;
    private:
        /* forbidden constructor */
        Enemy(void);
    public:
        Enemy(int hp, std::string const & type);
        Enemy(Enemy const & rhs);
        ~Enemy(void);
        std::string getType(void) const;
        virtual void deathDisplay(void) const;
        int getHitPoint(void) const;
        virtual void takeDamage(int amount);

        Enemy & operator=(Enemy const & rhs);
};
#endif