/*
TODO:

Get working decryption/encryption with a key (master password)
Find a way to store, display and format passwords
Get Adding, removing and changing passwords working
Catch CTRL-C and recrypt and save passwords to passwords.secure
*/

#include "../include/main.h"

std::filesystem::path encPassPath = "passwords.secured";
std::filesystem::path logPath = "log";
std::string decryptPassFile = "";
std::list<std::string> passwords;


int main() {
	// Initialization
	if (!std::filesystem::exists(encPassPath) || !std::filesystem::is_directory(logPath)) {
		int initErr = init();

		if (initErr == 2) {
			std::cout << "Initialization error 2: Log folder unable to be created.\n";
			return 2;
		}
		else if (initErr == 3) {
			std::cout << "Initialization error 3: Both log folder and passwords file were unable to be created.\n";
			return 2;
		}

	}
	
	clear();
	std::cout << "qPass Manager\nPlease enter a key:\n";
	hide();
	grabKey(key);
	show();

	return 0;
}




void hide() {
#ifndef _WIN32
	struct termios oldt, newt;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
#endif
}

void show() {
#ifndef _WIN32
	struct termios oldt;
	tcgetattr(STDIN_FILENO, &oldt);
	oldt.c_lflag |= (ICANON | ECHO); 
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif
}

void grabKey(std::string& key) {
	char ch;
#ifdef _WIN32
	while ((ch = _getch()) != '\r') {
		if (ch == '\b' && !key.empty()) {
			std::cout << "\b \b";
			key.pop_back();
		}
		else if (ch != '\b') {
			std::cout << "*";
			key += ch;
		}
	}
#else
	while ((ch = getchar()) != '\n') {
		if (ch == 127 && !key.empty()) {
			std::cout << "\b \b";
			key.pop_back();
		}
		else if (ch != 127) {
			std::cout << "*";
			key += ch;
		}
	}
#endif
}

int init() {
	int err = 0; 

	try {
		if (std::filesystem::create_directory("log")) {
			err += 0;
		}
	}
	catch (const std::filesystem::filesystem_error& e) {
		err = 2;
	}

	return err;
}

int decryptPasswords() {
	try {
		std::ofstream file("passwd.secure");
		if (file) {
			return 0;
		}
	}
	catch (const std::ios_base::failure& e) {
		return 1;
	}

	// Add accual decryption
}

void clear() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}