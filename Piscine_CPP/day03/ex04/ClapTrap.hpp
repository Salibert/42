
#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <iostream>
# include <sstream>

class ClapTrap {
    protected:
        std::string _name;

        unsigned int _level,
            _Hit_points,
            _Energy_points,
            _Max_hit_points,
            _Max_energy_points,
            _Melee_attack_damage,
            _Ranged_attack_damage,
            _Armor_damage_reduction;
    private:
            static unsigned int _nb_players; 
            
    public:
    // protected:
        /* constructor */
        ClapTrap(void);
        ClapTrap(std::string const & name);
        ClapTrap(ClapTrap const & src);

        /* destructor */

        virtual ~ClapTrap(void);

        /* Members functions*/
        virtual void rangedAttack(std::string const & target);
        virtual void meleeAttack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

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
        ClapTrap & operator=(ClapTrap const &  rhs);
};
#endif
