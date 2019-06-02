
#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    private:
        typedef void (ScavTrap::*_Func)(std::string const & target);
        _Func _list_attack[5];

    public:

        /* constructor */
        ScavTrap(void);
        ScavTrap(std::string const & name);
        ScavTrap(ScavTrap const & src);

        /* destructor */

        ~ScavTrap(void);

        /* Members functions*/
        void challenge1(std::string const & target);
        void challenge2(std::string const & target);
        void challenge3(std::string const & target);
        void challenge4(std::string const & target);
        void challenge5(std::string const & target);
        void challengeNewcomer(std::string const & target);

        /* operator */
        ScavTrap & operator=(ScavTrap const &  rhs);
};
#endif
