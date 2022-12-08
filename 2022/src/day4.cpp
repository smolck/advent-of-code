#include <iostream>
#include <sstream>
#include <tuple>
#include <functional>

#include "config.h"

template <typename T, typename SomeOtherLetterIdk>
using tup = std::tuple<T, SomeOtherLetterIdk>;

tup<int, int> parseRange(const std::string& str) {
    auto it = str.find('-');

    return std::make_pair(std::stoi(str.substr(0, it)), std::stoi(str.substr(it + 1, str.length())));
}

int partOneAnswer(const std::string& input) {
    std::stringstream ss(input);

    int total = 0;

    for (std::string line; std::getline(ss, line); ) {
        auto it = line.find(',');
        auto [start1, end1] = parseRange(line.substr(0, it));
        auto [start2, end2] = parseRange(line.substr(it + 1, line.length()));

        if ((start1 <= start2 && end1 >= end2) || (start2 <= start1 && end2 >= end1)) {
            total++;
        }
    }

    return total;
}

int partTwoAnswer(const std::string& input) {
    std::stringstream ss(input);

    int total = 0;

    for (std::string line; std::getline(ss, line); ) {
        auto it = line.find(',');
        auto [start1, end1] = parseRange(line.substr(0, it));
        auto [start2, end2] = parseRange(line.substr(it + 1, line.length()));

        if ((start1 <= start2 && end1 >= end2)
            || (start2 <= start1 && end2 >= end1)

            // Part two exclusive
            || (start1 <= start2 && end1 >= start2)
            || (start2 <= start1 && end2 >= start1)
            || (end1 >= end2 && start1 <= end2)
            || (end2 >= end1 && start2 <= end1)
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
