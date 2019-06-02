#include <iostream>

int main() {
    std::string initial = "HI THIS IS BRAIN";
    std::string* ptr = &initial;
    std::string& ref = initial;

    std::cout << "initial : " << initial << std::endl;
    std::cout << "ptr : " << *ptr << std::endl;
    std::cout << "ref : " << ref << std::endl;
}