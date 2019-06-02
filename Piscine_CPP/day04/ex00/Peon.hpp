#ifndef PEON_H
# define PEON_H
# include "Victim.hpp"
# include <iostream>

class Peon : public Victim {
    private:
        /* forbidden constructor */
        Peon(void);
    public:
        virtual void getPolymorphed(void) const;
        Peon(std::string const & name);
        Peon(Peon const & rhs);
        virtual ~Peon(void);
        /* operator */
        Peon & operator=(Peon const & rhs);
};

# endif