#include <iostream>

template <typename T, typename U>
void iter(T * array, int length, U (*f)(T x)) {
    for (int i = 0; i < length; i++)
        f(array[i]);
    std::cout << std::endl;
}

template <typename T>
void print(T x) {
    std::cout << " " << x;
}

int main(void)
{
    int tab[5] = {0, 1, 2, 3, 4};
    std::string tab2[2] = {"SALUT", "TOI"};

    std::cout << "int tab :";
    iter<int, void>(tab, 5, &print);
    std::cout << "char tab :";
    iter<std::string, void>(tab2, 2, &print);
    return 0;
}
