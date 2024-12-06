#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>


std::vector<int> parseStringToNumbers(const std::string& line) {
    std::vector<int> numbers;
    std::stringstream ss(line);
    int num;
    while (ss >> num) {
        numbers.push_back(num);
        if (ss.peek() == ' ') {
            ss.ignore();
        }
    }
    return numbers;
}

bool isAscendant(const std::vector<int>& numbers) {
    int j = 0;
    while (numbers[0 + j] == numbers[1 +j]){
        j += 1;
    }
    return (numbers[0+j] < numbers[1+j]);
}

bool isIncreasingOrDecreasing(const std::vector<int>& numbers) {
    bool ascendant = isAscendant(numbers);
    for (size_t i = 1; i < numbers.size(); ++i) {
        if ((abs(numbers[i] - numbers[i - 1]) > 3) || (abs(numbers[i] - numbers[i - 1]) == 0)){
            return false;
        }
        if (ascendant){
            if (i+1 != numbers.size()){
                if (numbers[i+1] < numbers[i]){
                    return false;
                }
            }
        }
        else {
            if (i+1 != numbers.size()){
                if (numbers[i+1] > numbers[i]){
                    return false;
                }
            }
        }
    }
    return true;
}

std::vector<int> copyExcept(const std::vector<int>& original, size_t excludeIndex) {
    std::vector<int> result;

    for (size_t i = 0; i < original.size(); ++i) {
        if (i != excludeIndex) {
            result.push_back(original[i]);
        }
    }

    return result;
}

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Can not open the file." << std::endl;
        return 1;
    }

    std::vector<int> column_1;
    std::string line;

    int lineNumber = 0;
    bool sum_plus = false;
    
    while (std::getline(file, line)) {
        sum_plus = false;
        std::vector<int> numbers = parseStringToNumbers(line);

        if (isIncreasingOrDecreasing(numbers)) {
            sum_plus = true;
        }
        else{
            for (size_t i = 0; i < numbers.size(); ++i) {
                std::vector<int> numbers_copy = copyExcept(numbers, i);
                
                if (isIncreasingOrDecreasing(numbers_copy)) {
                    sum_plus = true;
                }
            }
        }
        if (sum_plus) {
            lineNumber++;
        }
    }
    file.close();

  
    std::cout << "Solution: " << lineNumber << std::endl;
    
    return 0;
}
