#ifndef ISPACEMARINE_H
#define ISPACEMARINE_H

#include <iostream>

class ISpaceMarine {

    public:
        virtual ~ISpaceMarine(void) {};
        virtual ISpaceMarine* clone() const = 0;
        virtual void battleCry(void) const = 0;
        virtual void rangedAttack(int) const = 0;
        virtual void meleeAttack(void) = 0;
};

#endif