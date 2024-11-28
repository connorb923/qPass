#include "../include/main.h"
#include "../include/gen.h"
#include "../include/manager.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "No Arguments\n";
        displayHelp();
        return 1;
    }

    std::string command = argv[1];

    if (command == "help") {
        displayHelp();
        return 0;
    }
    else if (command == "add") {

    }
    else if (command == "remove") {

    }
    else if (command == "generate") {

    }
    else if (command == "list") {

    }
    else {
        std::cerr << "Bad Arguments: \n";
        for (int i = 0; i < argc; ++i) {
            std::cerr << "argv[" << i << "]: " << argv[i] << "\n";
        }
        displayHelp();
        return 1;
    }

    return 0;
}

void displayHelp() {
    std::cout << "qpass is a cli password manager writen in C++.\nUsage:\n"    << "qpass help\n          - Displays this message \n     qpass add [string name] [string password]\n          - Adds a password to the database.\n     qpass remove [string name]\n          - Removes a password from the database.\n     qpass generate [name] [true/false use special characters?] [int length]\n          - Generates a password then adds it to the database.\n     qpass list\n          - Lists all the passwords\n";
}