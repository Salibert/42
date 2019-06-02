#include "Character.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main() {
    Character *zaz = new Character("zaz");

    std::cout << *zaz;

    Enemy* b = new RadScorpion();
    Enemy* a = new SuperMutant();

    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();

    zaz->equip(pr);
    std::cout << *zaz;
    zaz->equip(pf);

    zaz->attack(b);
    std::cout << *zaz;
    zaz->equip(pr);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;
    zaz->recoverAP();
    std::cout << *zaz;
    zaz->recoverAP();
    std::cout << *zaz;
    zaz->equip(pf);
    zaz->attack(a);
    std::cout << *zaz;
    zaz->attack(a);
    std::cout << *zaz;
    zaz->attack(a);
    std::cout << *zaz;
    zaz->attack(a);
    std::cout << *zaz;
    zaz->attack(a);
    std::cout << *zaz;
    zaz->attack(a);
    std::cout << *zaz;

    return 0;
}