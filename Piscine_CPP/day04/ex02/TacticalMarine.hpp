#ifndef TACTICALMARINE_H
#define TACTICALMARINE_H

#include <string>
#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {

    public:
        TacticalMarine(void);
        TacticalMarine(TacticalMarine const & src );
        TacticalMarine & operator=(TacticalMarine const & rhs);
        ~TacticalMarine(void);

        TacticalMarine* clone(void) const;
        void battleCry(void) const;
        void rangedAttack(void) const;
        void meleeAttack(void) const;
};

#endif