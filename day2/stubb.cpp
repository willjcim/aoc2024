#include "../header.h"
#include "day2.cpp"

int main() {

	ifstream file("inputs/day_two.input"); 
    string content((istreambuf_iterator<char>(file)),
                         istreambuf_iterator<char>());

    auto part1 = timer<decltype(&partOne)>::time(partOne, content);

    //auto part2 = timer<decltype(&partTwo)>::time(partTwo, content);

	return 1;
}
