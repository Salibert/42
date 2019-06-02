#ifndef CASTCLASS_HPP
# define CASTCLASS_HPP

#include <iostream>
#include <cmath>
#include <limits>

class Cast {
    private:
        Cast(Cast const & rhs);
        Cast & operator=(Cast const & rhs);
    public:
        Cast(void);
        virtual ~Cast(void);

        void castChar(char* nb) const;
        void castInt(char* nb) const;
        void castFloat(char* nb) const;
        void castDouble(char* nb) const;
};
#endif