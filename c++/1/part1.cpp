#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>

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
            std::cerr << "Error al procesar una línea: " << line << std::endl;
        }
    }

    file.close();

    std::sort(column_1.begin(), column_1.end());
    std::sort(column_2.begin(), column_2.end());

    int sum_dif = 0;
    size_t size = std::min(column_1.size(), column_2.size());
    for (size_t i = 0; i < size; ++i) {
        sum_dif += std::abs(column_1[i] - column_2[i]);
    }

    std::cout << "Solution: " << sum_dif << std::endl;

    return 0;
}
