#include "Base.class.hpp"
#include <iostream>

void identify_from_pointer(Base * p) {
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
}

void identify_from_ref(Base & p) {
    try {
        p = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::bad_cast & e) {
        std::cout << e.what() << " A"  << std::endl;
    }
    try {
        p = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    } catch (std::bad_cast & e) {
        std::cout << e.what() << " B" << std::endl;
    }
    try {
        p = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (std::bad_cast & e) {
        std::cout << e.what() << " C"  << std::endl;
    }
}

Base * generate(void) {
    int i = rand() % 3;
    if (!i)
        return new A;
    else if (i == 1)
        return new B;
    else
        return new C; 
}

int main() {
    Base * base;
    srand(time(NULL));
    base = generate();
    identify_from_pointer(base);
    identify_from_ref(*base);
    delete base;
    return 0;
}