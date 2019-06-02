#include "Pony.hpp"

Pony::Pony(std::string name, std::string color,int nb_foot) : _name(name), _color(color), _nb_foot(nb_foot) {
    std::cout << name << " is born" << std::endl;
    return ;
}

Pony::~Pony(void){
    std::cout << this->_name << " is died and he had " << this->_nb_foot << " clog" << std::endl;
    return ;
}