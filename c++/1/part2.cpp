#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Can not open the file." << std::endl;
        return 1;
    }

    std::vector<int> column_1, column_2;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int num1, num2;
        if (iss >> num1 >> num2) {
            column_1.push_back(num1);
            column_2.push_back(num2);
        } else {
            std::cerr << "Error in line: " << line << std::endl;
        }
    }

    file.close();

    std::unordered_map<int, int> cont_column_2;
    for (int num : column_2) {
        cont_column_2[num]++;
    }

    int result = 0;
    for (int num : column_1) {
        if (cont_column_2.find(num) != cont_column_2.end()) {
            result += num * cont_column_2[num];
        }
    }

    std::cout << "Solution: " << result << std::endl;

    return 0;
}
