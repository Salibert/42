#include <iostream>

struct Data {std::string s1; int n; std::string s2; };

void* serialize(void) {
    std::string _random("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    std::cout << "Serialize" << std::endl;
    char* serialize = new char(22);
    for (int i=0; i < 8; i++)
        serialize[i] = _random[rand() % _random.length()];
    std::cout << "s1: " << serialize << std::endl;
    serialize[8] = '\0';
    int* nb  = reinterpret_cast<int*>(serialize + 9);
    *nb = 42;
    std::cout << "nb: "<< *nb << std::endl;
    for (int i=13; i < 21; i++)
        serialize[i] = _random[rand() % _random.length()];
    serialize[21] = '\0';
    std::cout << "s2: "<< &serialize[13] << std::endl;
    return static_cast<void *>(serialize);
}

Data* deserialize(void * raw) {
    Data* data = new Data;
    data->s1 = static_cast<char*>(raw);
    data->n = static_cast<char*>(raw)[9];
    data->s2 = &static_cast<char*>(raw)[13];
    return data;
}

int main() {
    srand(time(NULL));
    void *ptr = NULL;
    ptr = serialize();
    Data* data = deserialize(ptr);
    std::cout << std::endl << "Deserialize" << std::endl
    << "S1: " << data->s1 << std::endl
    << "N: " << data->n << std::endl
    << "S2: " << data->s2 << std::endl;
    return 0;
}