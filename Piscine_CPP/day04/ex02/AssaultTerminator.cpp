#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator(void) {
  std::cout << "* teleports from space *" << std::endl;
  return;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator & src) {
  (void)src;
  return;
}

AssaultTerminator::~AssaultTerminator(void) {
  std::cout << "I’ll be back ..." << std::endl;
  delete this;
  return;
}

AssaultTerminator* AssaultTerminator::clone(void) const {
  return new AssaultTerminator( *this );
}

void AssaultTerminator::battleCry() const {
  std::cout << "This code is unclean. PURIFY IT !" << std::endl;
  return;
}

void AssaultTerminator::rangedAttack() const {
  std::cout << "* does nothing *" << std::endl;
  return;
}

void AssaultTerminator::meleeAttack() const {
  std::cout << "* attacks with chainfists *" << std::endl;
  return;
}

AssaultTerminator & AssaultTerminator::operator=(const AssaultTerminator & rhs) {
    (void)rhs;
    return *this;
}