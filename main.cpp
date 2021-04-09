#include <iostream>
#include <fstream>
#include "source/decryptor.h"



int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "usage: \'" << argv[1] << " <filename>\'";
        return 1;
    }

    Decryptor decryptor(argv[1]);

    for (;;) {
		std::string key;
		std::cout << "Input key: ";
		if (!(std::cin >> key)) {
			break;
		}
		int result = decryptor.decrypt(key);
		if (result == -1) {
			std::cout << "Key not found\n";
		} else {
			std::cout << "Key position: " << result << '\n';
		}
	}
}