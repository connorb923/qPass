#include "../include/main.h"
#include "../include/gen.h"
#include "../include/manager.h"

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
        if (argc < 4) {
            std::cerr << "Insufficient arguments for 'generate'.\n";
            displayHelp();
            return 1;
        }

        std::string name = argv[2];
        int length = std::stoi(argv[3]);

        std::string password = passGen(length);

        std::cout << "Password: " << password << " generated for " << name << "\n";
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
    std::cout << "qpass is a cli password manager written in C++.\nUsage:\n"
        << "    qpass help\n          - Displays this message \n"
        << "    qpass add [string name] [string password]\n          - Adds a password to the database.\n"
        << "    qpass remove [string name]\n          - Removes a password from the database.\n"
        << "    qpass generate [name] [int length]\n          - Generates a password then adds it to the database.\n"
        << "    qpass list\n          - Lists all the passwords\n";
}