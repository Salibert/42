
#ifndef SUPERTRAP_H
# define SUPERTRAP_H

# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {
    private:
        /* forbidden constructor */
        SuperTrap(void);
    public:

        /* constructor */

        SuperTrap(std::string const & name);
        SuperTrap(SuperTrap const & src);

        /* destructor */

        ~SuperTrap(void);      
        /* operator */
        SuperTrap & operator=(SuperTrap const &  rhs);

        /* members func */
        void rangedAttack(std::string const & target);
        void meleeAttack(std::string const & target);
};
#endif
