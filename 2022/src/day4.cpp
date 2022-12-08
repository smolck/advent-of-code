#include <iostream>
#include <sstream>
#include <utility>

#include "config.h"

bool rangesOverlap(const std::pair<int, int>& range1, const std::pair<int, int>& range2) {
    return (range1.first <= range2.first && range1.second >= range2.second)
        || (range2.first <= range1.first && range2.second >= range1.second);
}

int partOneAnswer(const std::string& input) {
    std::stringstream ss(input);
    int total = 0;

    for (std::string line; std::getline(ss, line); ) {
        std::istringstream iss(line);
        std::pair<int, int> range1, range2;
        char c;
        iss >> range1.first >> c >> range1.second >> c >> range2.first >> c >> range2.second;
        if (rangesOverlap(range1, range2)) {
            total++;
        }
    }

    return total;
}

int partTwoAnswer(const std::string& input) {
    std::stringstream ss(input);
    int total = 0;

    for (std::string line; std::getline(ss, line); ) {
        std::istringstream iss(line);
        std::pair<int, int> range1, range2;
        char c;
        iss >> range1.first >> c >> range1.second >> c >> range2.first >> c >> range2.second;

        if (rangesOverlap(range1, range2)
            // Part two exclusive
            || (range1.first <= range2.first && range1.second >= range2.first)
            || (range2.first <= range1.first && range2.second >= range1.first)
            || (range1.second >= range2.second && range1.first <= range2.second)
            || (range2.second >= range1.second && range2.first <= range1.second)
        ) {
            total++;
        }
    }

    return total;
}

int main() {
    std::cout << "Example input part one answer: " << partOneAnswer(DAY4_EXAMPLE_INPUT) << "\n";
    std::cout << "Example input part two answer: " << partTwoAnswer(DAY4_EXAMPLE_INPUT) << "\n";

    std::cout << "Part one answer: " << partOneAnswer(DAY4_INPUT) << "\n";
    std::cout << "Part two answer: " << partTwoAnswer(DAY4_INPUT) << "\n";
}
