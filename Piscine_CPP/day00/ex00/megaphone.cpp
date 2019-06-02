#include <iostream>

int main(int ac, char** av) {
    if (ac != 1)
        for (int n=1; n < ac; n++){
            std::string str(av[n]);
            for (size_t i=0; i<str.length(); ++i){
                str[i] = std::toupper(str[i]);
            }
            std::cout << str;
        }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return 0;
}