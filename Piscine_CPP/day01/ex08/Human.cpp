#include "Human.hpp"

void Human::meleeAttack(std::string const & target) {
    std::cout << "melee " << target << std::endl;
    return;
}

void Human::rangedAttack(std::string const & target) {
    std::cout << "range " << target << std::endl;
    return;
}

void Human::intimidatingShout(std::string const & target) {
    std::cout << "intimidating " << target << std::endl;
    return;
}

void Human::action(std::string const & action_name, std::string const & target) {
    typedef void (Human::*Func)(std::string const & target);
    struct {
        Func func;
        std::string const key;
    } array[3] = {
        { &Human::meleeAttack, "melee" },
        { &Human::rangedAttack, "range"  },
        { &Human::intimidatingShout, "intimidating" },
    };

    std::cout << "Human attack with ";
    for (int i=0; i < 3; i++)
        if (array[i].key == action_name )
            return (this->*(array[i].func))(target);
    return;
}