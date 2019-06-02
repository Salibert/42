#ifndef Sorcerer_H
# define Sorcerer_H
# include "Victim.hpp"

class Sorcerer {
    private:
        std::string _name, _title;
        /* forbidden constructor */
        Sorcerer(void);
    public:
        void polymorph(Victim const &) const;
        Sorcerer(std::string const & name,std::string const & _title);
        Sorcerer(Sorcerer const & rhs);
        ~Sorcerer(void);

        /* get */
            std::string get_name(void) const;
            std::string get_title(void) const;
        /* set */
            void set_name(std::string const & name);
            void set_title(std::string const & title);

        /* operator */
        Sorcerer & operator=(Sorcerer const & rhs);
};
std::ostream & operator<<(std::ostream & o, Sorcerer const & wahiba);
# endif