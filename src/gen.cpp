#include "../include/gen.h"

const std::string allowedwSpecialCharacters = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ1234567890!.$#&{([])}\|/,:@";
const std::string allowednSpecialCharacters = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ1234567890";

static std::random_device rd;
static std::mt19937 rng(rd());


char randomChar(bool specialChar) {
    if (specialChar) {
        static std::uniform_int_distribution<size_t> dist(0, allowedwSpecialCharacters.size() - 1);
        return allowedwSpecialCharacters[dist(rng)];
    }
    else
    {
        static std::uniform_int_distribution<size_t> dist(0, allowednSpecialCharacters.size() - 1);
        return allowednSpecialCharacters[dist(rng)];
    }

}

std::string passGen(bool specialCharacters, int length) {
    std::vector<char> passVec(length);
    for (int i = 0; i < length; ++i) {
        passVec[i] = randomChar(specialCharacters);
    }

    return std::string(passVec.begin(), passVec.end());
}
