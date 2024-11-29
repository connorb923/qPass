#pragma once

#include <fstream>;
#include <iostream>;
#include <list>
#include <stdlib.h>
#include <filesystem>;

#ifdef _WIN32
#include <conio.h>  // For _getch() on Windows
#else
#include <termios.h>  // For termios on Unix-based systems (Linux/macOS)
#include <unistd.h>
#endif

std::string key;

int init();
int decryptPasswords();
void clear();
void grabKey(std::string& key);
void hide();
void show();