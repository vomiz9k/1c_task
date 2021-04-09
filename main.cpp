#include <iostream>
#include <fstream>
#include "source/decryptor.h"



int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "usage: \'" << argv[1] << " <filename>\'";
        return 1;
    }

    Decryptor decryptor(argv[1]);
    std::string key;
    while (std::cin >> key) {
        std::cout << "result: " << decryptor.decrypt(key) << std::endl;
    }
}