
#ifndef FRAGTRAP_H
# define FRAGTRAP_H
# include <iostream>

class FragTrap {
    private:
        typedef void (FragTrap::*_Func)(std::string const & target);
        std::string _name;

        unsigned int _level,
            _Hit_points,
            _Energy_points,
            _Max_hit_points,
            _Max_energy_points,
            _Melee_attack_damage,
            _Ranged_attack_damage,
            _Armor_damage_reduction;

        _Func _list_attack[5];

        /* forbidden constructor */
        FragTrap(void);
    public:

        /* constructor */

        FragTrap(std::string const & name);
        FragTrap(FragTrap const & src);

        /* destructor */

        ~FragTrap(void);

        /* Members functions*/
        void superFlang(std::string const & target);
        void eggBomb(std::string const & target);
        void miniTail(std::string const & target);
        void yawn(std::string const & target);
        void boomburst(std::string const & target);
        void rangedAttack(std::string const & target);
        void meleeAttack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void vaulthunter_dot_exe(std::string const & target);

            /* get */
            int get_Hit_points(void) const ;
            int get_Max_hit_points(void) const;
            int get_Energy_points(void) const;
            int get_Max_energy_points(void) const;
            int get_level(void) const;
            int get_Melee_attack_damage(void) const;
            int get_Ranged_attack_damage(void) const;
            int get_Armor_damage_reduction(void) const;
            std::string get_name(void) const ;
            /* set */
            void set_Hit_points(unsigned int const hp);
            void set_Max_hit_points(unsigned int const max_hit_p);
            void set_Energy_points(unsigned int const energie_p);
            void set_Max_energy_points(unsigned int const max_energie_p);
            void set_level(unsigned int const level);
            void set_Melee_attack_damage(unsigned int const attack_damage);
            void set_Ranged_attack_damage(unsigned int const attack_damage);
            void set_Armor_damage_reduction(unsigned int const damage_red);
            void set_name(std::string const & name);
        
        /* operator */
        FragTrap & operator=(FragTrap const &  rhs);
};
#endif
