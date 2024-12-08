#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Can not open the file." << std::endl;
        return 1;
    }
    // std::string input = "xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))";

    std::regex pattern(R"(mul\((\d+),(\d+)\))");
    std::smatch matches;

    int totalSum = 0;

    std::string input;

    while (std::getline(file, input)) {
        std::sregex_iterator currentMatch(input.begin(), input.end(), pattern);
        std::sregex_iterator end;

        while (currentMatch != end) {
            matches = *currentMatch;
            int x = std::stoi(matches[1]);
            int y = std::stoi(matches[2]);

            totalSum += x * y;

            ++currentMatch;
        }
    }
    std::cout << "Result: " << totalSum << "\n";

    return 0;
}