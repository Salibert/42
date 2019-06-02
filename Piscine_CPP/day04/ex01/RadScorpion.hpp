#ifndef RADSCORPION_H
# define RADSCORPION_H
# include "Enemy.hpp"

class RadScorpion : public Enemy {
    private:
        /* forbidden constructor*/
        RadScorpion(int hp, std::string const & type);
        RadScorpion(RadScorpion const & rhs);
    public:
        RadScorpion(void);
        ~RadScorpion(void);
        virtual void deathDisplay(void) const;
        std::string getType(void) const;
        int getHitPoint(void) const;

        RadScorpion & operator=(RadScorpion const & rhs);
};
#endif