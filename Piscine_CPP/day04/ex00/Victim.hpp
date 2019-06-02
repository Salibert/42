#ifndef VICTIM_H
# define VICTIM_H

# include <iostream>

class Victim {
    private:
        std::string _name;
        
    protected:
        /* forbidden constructor */
        Victim(void);
    public:
        virtual void getPolymorphed(void) const;
        Victim(std::string const & name);
        Victim(Victim const & rhs);
        virtual ~Victim(void);

        /* get */
            std::string get_name(void) const;
        /* set */
            void set_name(std::string const & name);
        /* operator */
        Victim & operator=(Victim const & rhs);
};
    std::ostream & operator<<(std::ostream & o, Victim const & rhs);
# endif