#ifndef BRAIN_H
# define BRAIN_H
#include <iostream>
#include <sstream>
class Brain {
    std::string _conciance;
    Brain* const _brain;
    public:
        std::string identify(void) const ;
        Brain(void);
        ~Brain(void);
};

#endif