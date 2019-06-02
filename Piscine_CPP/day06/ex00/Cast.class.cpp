#include "Cast.class.hpp"

Cast::Cast(void) { return; }

Cast::~Cast(void) { return; }

Cast::Cast(Cast const & rhs) { *this = rhs; return;}

Cast & Cast::operator=(Cast const & rhs) {
    if (this != &rhs)
        *this = rhs;
    return *this;
}

void Cast::castChar(char *nb) const {
    std::cout << "Char : ";
    try {
        int cast = std::stoi(std::string(nb));
        if (cast > 255 || cast < 0 )
            std::cout << "Impossible" << std::endl;
        else if (!isprint(static_cast<char>(cast)))
            std::cout << " Non displayable " << std::endl;
        else
            std::cout << "'" << static_cast<char>(cast) << "'" << std::endl;
    } catch (std::exception & e) {
        std::cout << "impossible" << std::endl;
    }
}
void Cast::castInt(char *nb) const {
    std::cout << "Int : ";
    try {
        int cast = std::stoi(std::string(nb));
        std::cout << cast << std::endl;
    } catch (std::exception & e) {
        std::cout << "impossible" << std::endl;
    }

}
void Cast::castFloat(char *nb) const {
    std::cout << "Float : ";
    try {
        float cast = std::stof(std::string(nb));
        std::cout << cast;
        if(std::fmodf(cast, 1) == 0)
            std::cout << ".0";
        std::cout << "f";
    } catch (std::exception & e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}

void Cast::castDouble(char *nb) const {
    std::cout << "Double : ";
    try {
        double cast = std::stod(std::string(nb));
        std::cout << cast;
        if(std::fmod(cast, 1) == 0)
            std::cout << ".0";
    } catch (std::exception & e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}