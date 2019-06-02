
#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
    private:
        typedef void (FragTrap::*_Func)(std::string const & target);
        _Func _list_attack[5];

    
    public:
    // protected:
        /* constructor */
        FragTrap(void);
        FragTrap(std::string const & name);
        FragTrap(FragTrap const & src);
        /* destructor */

        virtual ~FragTrap(void);

        /* Members functions*/
        virtual void rangedAttack(std::string const & target);
        void superFlang(std::string const & target);
        void eggBomb(std::string const & target);
        void miniTail(std::string const & target);
        void yawn(std::string const & target);
        void boomburst(std::string const & target);
        void vaulthunter_dot_exe(std::string const & target);
        
        /* operator */
        FragTrap & operator=(FragTrap const &  rhs);
};
#endif
