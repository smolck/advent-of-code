#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "config.h"

#define MAX(x, y) ((x > y) ? (x) : (y))

int answerPartOne(const std::string& input) {
    std::stringstream ss(input);

    int max = 0;
    int current = 0;

    for (std::string line; std::getline(ss, line); ) {
        if (line.empty()) {
            // End of elf so do the stuff
            max = MAX(max, current);
            current = 0;
        } else {
            int calories = std::stoi(line);
            current += calories;
        }
    }

    // loop ends without doing this for the last elf, so do it now
    max = MAX(max, current);

    return max;
}

int answerPartTwo(const std::string& input) {
    std::stringstream ss(input);

    std::vector<int> stuff;
    int current = 0;

    for (std::string line; std::getline(ss, line); ) {
        if (line.empty()) {
            // End of elf so do the stuff
            stuff.push_back(current);
            current = 0;
        } else {
            int calories = std::stoi(line);
            current += calories;
        }
    }

    // loop ends without doing this for the last elf, so do it now
    stuff.push_back(current);

    std::sort(stuff.rbegin(), stuff.rend());

    return stuff[0] + stuff[1] + stuff[2];
}

int main() {
    std::cout << "Example answer part one: " << answerPartOne(DAY1_EXAMPLE_INPUT) << "\n";
    std::cout << "Example answer part two: " << answerPartTwo(DAY1_EXAMPLE_INPUT) << "\n";

    std::cout << "Part 1 answer: " << answerPartOne(DAY1_INPUT) << "\n";
    std::cout << "Part 2 answer: " << answerPartTwo(DAY1_INPUT) << "\n";
}
