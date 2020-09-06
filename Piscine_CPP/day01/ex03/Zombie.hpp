#ifndef ZOMBIE_H
# define ZOMBIE_H
#include <iostream>

class Zombie {
    static std::string _random;
    std::string _name;
    int         _type;
    int         health;
    public:
        Zombie(void);
        ~Zombie(void);
        Zombie(std::string name, int type);
        void announce(void);
};

#endif