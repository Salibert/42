
#ifndef NINJATRAP_H
# define NINJATRAP_H

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {
    private:
        /* forbidden constructor */
        NinjaTrap(void);
    public:

        /* constructor */

        NinjaTrap(std::string const & name);
        NinjaTrap(NinjaTrap const & src);

        /* destructor */

        ~NinjaTrap(void);

        /* Members functions*/
        void ninjaShoebox(ClapTrap const & rhs) const;
        void ninjaShoebox(FragTrap const & rhs) const;
        void ninjaShoebox(ScavTrap const & rhs) const;
        void ninjaShoebox(NinjaTrap const & rhs) const;
        
        /* operator */
        NinjaTrap & operator=(NinjaTrap const &  rhs);
};
#endif
