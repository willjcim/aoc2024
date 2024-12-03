#include "../header.h"
#include "day3.cpp"

int main() {

	ifstream file("inputs/day_three.input"); 
    string content((istreambuf_iterator<char>(file)),
                         istreambuf_iterator<char>());

    auto part1 = timer<decltype(&partOne)>::time(partOne, content);
    cout << "Part 1: " << part1 << "\n";

    auto part2 = timer<decltype(&partTwo)>::time(partTwo, content);
    cout << "Part 2: " << part2 << "\n";

    auto part1Dumb = timer<decltype(&partOneDumb)>::time(partOneDumb, content);
    cout << "Part 1 (dumb): " << part1Dumb << "\n";

    auto part2Dumb = timer<decltype(&partTwoDumb)>::time(partTwoDumb, content);
    cout << "Part 2 (dumb): " << part2Dumb << "\n";

	return 1;
}
