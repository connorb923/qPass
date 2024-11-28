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
        if (argc != 5) {
            std::cerr << "Insufficient arguments for 'generate'.\n";
            for (int i = 0; i < argc; ++i) {
                std::cerr << "argv[" << i << "]: " << argv[i] << "\n";
            }
            displayHelp();
            return 1;
        }

        std::string name = argv[2];
        std::string allowSpecial = argv[3];
        int length = std::stoi(argv[4]);

        if (allowSpecial == "y" || allowSpecial == "Y" || allowSpecial == "n" || allowSpecial == "N") {

            std::string password;

            if (allowSpecial == "y" || allowSpecial == "Y") {
                password = passGen(true,length);
            }
            else {
                password = passGen(false, length);
            }


            std::cout << "Password: " << password << " generated for " << name << "\n";
        }
        else {
            std::cerr << "Invalid Argument 3! " << allowSpecial;
        }

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
        << "    qpass generate [name] [y/n special characters] [int length]\n          - Generates a password then adds it to the database.\n"
        << "    qpass list\n          - Lists all the passwords\n";
}