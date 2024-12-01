#include "../header.h"

int main() {
	vector<int> listOne;
	vector<int> listTwo;

	populateInputs(listOne, listTwo);

	// Day 1 Part 1
	int partOneSol = partOne(listOne, listTwo);
	cout << "Day 1 Part 1 solution: " << partOneSol << "\n";

	// Day 1 Part 2
	int partTwoSol = partTwo(listOne, listTwo);
	cout << "Day 1 Part 2 solution: " << partTwoSol << "\n";
	
	return 1;
}
