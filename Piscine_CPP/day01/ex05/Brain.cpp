#include "Brain.hpp"

Brain::Brain(void) : _brain(this) {
    this->_conciance = "Billy";
    std::cout << "Hello, I am "<< this->_conciance <<" the brain of bob " << std::endl;
    return;
}

Brain::~Brain(void) {
    return;
}

std::string Brain::identify(void) const {
    std::stringstream ss;
    ss << (const void*)(this->_brain);
    std::string name = ss.str();
    return name;
}