#include "ZombieEvent.hpp"

int main() {
    ZombieEvent ze = ZombieEvent(1);
    Zombie* billy = ze.newZombie("BILLY");
    std::cout << "Billy saw a human and scream BRAIIIIIIIIIIINS to alert, these zombie friends" << std::endl;
    for (int i=0; i < 5; i++) {
       ze.setZombieType(i) ;
       ze.randomChump();
    }
    std::cout << "In front of the weakness of his friends, Billy leaves died" << std::endl;
    delete billy;
    return 0;
}