#ifndef PONY_H
# define PONY_H
#include <iostream>

class Pony {
    std::string _name;
    std::string _color;
    int         _nb_foot;
    public:
        Pony(std::string name, std::string color, int nb_foot);
        ~Pony(void);
};
#endif