#include "Array.hpp"

int main(void) {
        std::cout << "Array a :";
        Array<std::string> a(1);
        a[0] = " SALUT";
        std::cout << a[0] << std::endl;
        Array<std::string> b(2);
        std::cout << "a = b : ";
        b[0] = "TOI";
        b[1] = "!!!";
        a = b;

        std::cout << a[0] << " ";
        try {
            std::cout << a[2] << std::endl;
        } catch(...) {
            std::cout << "exception" << std::endl;
        }
    return 0;
}
