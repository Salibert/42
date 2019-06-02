#ifndef ZOMBIEEVENT_H
# define ZOMBIEEVENT_H
# include "Zombie.hpp"

class ZombieEvent {
    int _type;
    static std::string _random;
    public:
        ~ZombieEvent(void);
        ZombieEvent(int type);
        Zombie* newZombie(std::string name);
        void setZombieType(int type);
        void randomChump(void);
};

#endif