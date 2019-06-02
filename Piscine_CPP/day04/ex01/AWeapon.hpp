#ifndef AWEAPON_H
# define AWEAPON_H
# include <iostream>

class AWeapon {
    protected:
        std::string _name;
        int _damage;
        int _APCost;
    private:
        /* forbidden constructor */
        AWeapon(void);
    public:
        AWeapon(std::string const & name, int apcost, int damage);
        AWeapon(AWeapon const & rhs);

        virtual ~AWeapon(void);

        AWeapon & operator=(AWeapon const & rhs);

        std::string getName(void) const;
        int getAPCost(void) const;
        int getDamage(void) const;

        virtual void attack() const = 0;
};

#endif