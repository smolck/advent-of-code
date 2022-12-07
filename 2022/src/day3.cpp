#include <iostream>
#include <sstream>
#include <vector>

#include "config.h"

inline int priority(char c) {
    return c - 96 < 0 ? c - 38 : c - 96;
}

int partOneAnswer(const std::string& input) {
    std::stringstream ss(input);

    int prioSum = 0;

    for (std::string line; std::getline(ss, line); ) {
        size_t len = line.length();
        std::sort(line.begin(), line.begin() + (len / 2));
        std::sort(line.begin() + (len / 2), line.end());

        std::vector<char> i;
        i.reserve(1);

        std::set_intersection(line.begin(), line.begin() + (len / 2),
                              line.begin() + (len / 2), line.end(),
                              i.begin());

        prioSum += priority(i[0]);
    }

    return prioSum;
}

int partTwoAnswer(const std::string& input) {
    std::stringstream ss(input);

    int prioSum = 0;

    for (std::string line1, line2, line3; std::getline(ss, line1), std::getline(ss, line2), std::getline(ss, line3); ) {
        for (const auto& c : line1) {
            if (line2.find(c) != std::string::npos && line3.find(c) != std::string::npos) {
                prioSum += priority(c);
                break;
            }
        }
    }

    return prioSum;
}

int main() {
    std::cout << "Example Part 1 answer: " << partOneAnswer(DAY3_EXAMPLE_INPUT) << "\n";
    std::cout << "Example Part 2 answer: " << partTwoAnswer(DAY3_EXAMPLE_INPUT) << "\n";

    std::cout << "Part 1 answer: " << partOneAnswer(DAY3_INPUT) << "\n";
    std::cout << "Part 2 answer: " << partTwoAnswer(DAY3_INPUT) << "\n";
}
