#include "Human.hpp"

Human::Human(void) {
    return;
}

Human::~Human(void) {
    return;
}

std::string Human::identify(void) {
    return this->_brain.identify();
}

Brain Human::getBrain(void) const {
    return this->_brain;
}