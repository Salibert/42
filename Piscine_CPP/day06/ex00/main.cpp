#include "Cast.class.hpp"

int main(int ac, char **av) {
    if (ac == 2) {
        Cast cast;
        cast.castChar(av[1]);
        cast.castInt(av[1]);
        cast.castFloat(av[1]);
        cast.castDouble(av[1]);
    } else {
        std::cout << "./convert [one param]" << std::endl;
    }
}