#include "../include/gen.h"

const std::string allowedCharacters = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ1234567890!.$#&([])";

static std::random_device rd;
static std::mt19937 rng(rd());
static std::uniform_int_distribution<size_t> dist(0, allowedCharacters.size() - 1);

char randomChar() {
    return allowedCharacters[dist(rng)];
}

std::string passGen(int length) {
    std::vector<char> passVec(length);
    for (int i = 0; i < length; ++i) {
        passVec[i] = randomChar();
    }

    return std::string(passVec.begin(), passVec.end());
}
