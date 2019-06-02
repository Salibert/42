#ifndef HUMAN_H
# define HUMAN_H
# include "Brain.hpp"

class Human {
    const Brain _brain;

    public:
        Brain getBrain(void) const ;
        std::string identify(void);
        Human(void);
        ~Human(void);
};

#endif