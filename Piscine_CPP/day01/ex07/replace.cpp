#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/stat.h>

bool exists_file(const std::string& name) {
  struct stat buffer;
  if (stat(name.c_str(), &buffer) == 0) {
      return S_ISREG(buffer.st_mode);
  }
  return false; 
}

std::string search_and_replace(std::string wire, const std::string& s1, const std::string& s2) {
    size_t pos = 0;
    while ((pos = wire.find(s1, pos)) != -1) {
         wire.replace(pos, s1.length(), s2);
         pos += s2.length();
    }
    return wire;
}

int main(int ac, char **av) {
    std::string filename;
    if (ac == 4) {
        for (int i=1; i < ac; i++){
            if (std::string(av[i]).empty()) {
                std::cout << "find empty input" << std::endl;
                return 0;
            }
        }
        if (exists_file(av[1]))
                filename = std::string(av[1]);
        else {
            std::cout << "error file" << std::endl;
            return 0;
        }
        std::stringstream buffer;
        std::ifstream ifs(av[1]);
        std::ofstream ofs(std::string(av[1]) + ".replace");
        if (!ifs || !ofs )
            return 0;
        buffer << ifs.rdbuf();
        ofs << search_and_replace(buffer.str(), std::string(av[2]), std::string(av[3]));
        ifs.close();
        ofs.close();        
    }
    return 0;
}