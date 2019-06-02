#ifndef ZOMBIEHORDE_H
# define ZOMBIEHORDE_H
# include "Zombie.hpp"

class ZombieHorde {
    Zombie* _horde;
    int _len_horde;
    public:
        ~ZombieHorde(void);
        ZombieHorde(int n);
        void announce(void);
};

#endif