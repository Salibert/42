#ifndef ASSAULTTERMINATOR_H
#define ASSAULTTERMINATOR_H

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {

    public:
        AssaultTerminator( void );
        AssaultTerminator(AssaultTerminator const & src);
        AssaultTerminator & operator=(AssaultTerminator const & rhs);
        ~AssaultTerminator( void );

        AssaultTerminator* clone(void) const;
        void battleCry() const;
        void rangedAttack() const;
        void meleeAttack() const;
};

#endif