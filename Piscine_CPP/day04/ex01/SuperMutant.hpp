#ifndef SUPERMUTANT_H
# define SUPERMUTANT_H
# include "Enemy.hpp"

class SuperMutant : public Enemy {
    private:
        /* forbidden constructor*/
        SuperMutant(int hp, std::string const & type);
        SuperMutant(SuperMutant const & rhs);
    public:
        SuperMutant(void);
        ~SuperMutant(void);
        std::string getType(void) const;
        virtual void deathDisplay(void) const;
        int getHitPoint(void) const;
        virtual void takeDamage(int amount);

        SuperMutant & operator=(SuperMutant const & rhs);
};
#endif