#include "Pony.hpp"

Pony *ponyOnTheHeap(std::string name, std::string color, int nb_foot) {
    return new Pony(name, color, nb_foot);
}

void ponyOnTheStack(std::string name, std::string color, int nb_foot) {
    Pony stack = Pony(name, color, nb_foot);
    return ;
}

int main() {
    int nb_foot = 2;
    std::cout << "invoke on Heap" << std::endl;
    Pony* heap = ponyOnTheHeap("pony on the heap", "green",nb_foot);
    std::cout << "invoke on Stack" << std::endl;
    ponyOnTheStack("pony on the stack", "red",nb_foot + 1);
    delete heap;
    return 0;
}