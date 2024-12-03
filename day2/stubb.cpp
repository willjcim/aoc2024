#include "../header.h"
#include "day2.cpp"

int main() {

	ifstream file("inputs/day_two.input"); 
    string content((istreambuf_iterator<char>(file)),
                         istreambuf_iterator<char>());

    auto part1 = timer<decltype(&partOne)>::time(partOne, content);
    cout << "Part 1: " << part1 << "\n";

    auto part2 = timer<decltype(&partTwo)>::time(partTwo, content);
    cout << "Part 2: " << part2 << "\n";

	return 1;
}
