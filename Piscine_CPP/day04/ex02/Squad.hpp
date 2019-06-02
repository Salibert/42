#ifndef ISQUAD_H
# define ISQUAD_H

# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

class Squad {
    private:
        int _count;
        ISpaceMarine** _company;
    public:
        Squad(void);
        Squad(Squad const & src);
        Squad & operator=(Squad const & rhs);
        ~Squad(void);

        int getCount(void) const;
        ISpaceMarine* getUnit(int) const;
        int push(ISpaceMarine*);
};

#endif