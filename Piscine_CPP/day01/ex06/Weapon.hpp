#ifndef WEAPON_H
# define WEAPON_H
# include <iostream>
class Weapon {
        std::string _type;
    public:
        Weapon(std::string type);
        ~Weapon(void);
        std::string& getType(void);
        void setType(std::string type);
};
#endif