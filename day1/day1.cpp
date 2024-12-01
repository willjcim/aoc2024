#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Solves Day 1 Part 1
// O(n log n)
int partOne(vector<int> listOne, vector<int> listTwo) {
    // sort vectors 
    sort(listOne.begin(), listOne.end());
    sort(listTwo.begin(), listTwo.end());

    int total = 0;
    for (int i = 0; i < listOne.size(); i++) {
        int tmp = listOne[i] - listTwo[i];
        if (tmp < 0) {
            tmp *= -1;
        }
        total += tmp;
    }
    return total;
}

// Solves Day 1 Part 2
// O(n log n)
int partTwo(vector<int> listOne, vector<int> listTwo) {
    // sort vectors
    sort(listOne.begin(), listOne.end());
    sort(listTwo.begin(), listTwo.end());
    
    int total = 0;
    for (int i = 0; i < listOne.size(); i++) {
        auto duplicates = equal_range(listTwo.begin(), listTwo.end(), listOne[i]);
        int frequency = duplicates.second - duplicates.first;

        total += frequency * listOne[i];
    }

    return total;
}

void populateInputs(vector<int>& vOne, vector<int>& vTwo) {
    ifstream file("inputs/day_one.input");
    string str;
    while (getline(file, str)) {
        istringstream iss(str);
        string sIntOne, sIntTwo;

        getline(iss, sIntOne, ' ');
        getline(iss, sIntTwo, '\0');

        vOne.push_back(stoi(sIntOne));
        vTwo.push_back(stoi(sIntTwo));
    }
}
