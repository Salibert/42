
#ifndef NINJATRAP_H
# define NINJATRAP_H

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap {


    public:
    // protected:
        /* constructor */
        NinjaTrap(void);
        NinjaTrap(std::string const & name);
        NinjaTrap(NinjaTrap const & src);

        /* destructor */
        virtual ~NinjaTrap(void);

        /* Members functions*/
        virtual void meleeAttack(std::string const & target);
        void ninjaShoebox(ClapTrap const & rhs) const;
        void ninjaShoebox(FragTrap const & rhs) const;
        void ninjaShoebox(ScavTrap const & rhs) const;
        void ninjaShoebox(NinjaTrap const & rhs) const;
        
        /* operator */
        NinjaTrap & operator=(NinjaTrap const &  rhs);
};
#endif
