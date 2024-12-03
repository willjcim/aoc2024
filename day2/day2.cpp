#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;



// https://stackoverflow.com/questions/236129/how-do-i-iterate-over-the-words-of-a-string
template <typename Out>
void split(const string &s, char delim, Out result) {
    istringstream iss(s);
    string item;
    while (getline(iss, item, delim)) {
        *result++ = item;
    }
}

vector<int> split(const string &s, char delim) {
    vector<string> sLevels;
    vector<int> iLevels;
    split(s, delim, back_inserter(sLevels));
    transform(sLevels.begin(), sLevels.end(), std::back_inserter(iLevels),
               [](const std::string& str) { return std::stoi(str); });
    return iLevels;
}

// Solves Day 2 Part 1
int partOne(string inputText) {
    int safeReports = 0;
    
    istringstream iss(inputText);
    string str;
    while (getline(iss, str)) {
        vector<int> report = split(str, ' ');

        bool safe = true;
        // true for increment
        // false for decrement
        bool direction = (report[0] < report[1]); 
        for (int i = 0; i < report.size() - 1; i++) {
            if ((report[i] < report[i+1]) != direction) {
                safe = false;
            }
            if (report[i] == report[i+1]) {
                safe = false;
            } else if (abs(report[i] - report[i+1]) > 3) {
                safe = false;
            }
        }
        safeReports += safe;   
    }
    cout << "Part 1: " << safeReports << "\n";
    return 1;
}

int checkSafety(vector<int> report, int pop) {
    if (pop > -1) {
        auto it = find(report.begin(), report.end(), pop);
        // check that there actually is a 3 in our vector
        if (it != report.end()) {
            report.erase(it);
        }
    }
    cout << "Report: ";
    for (auto i: report)
        cout << i << ' ';
    cout << endl;
    cout << "Pop Len: " << report.size() << endl;
    // true for increment
    // false for decrement›
    bool direction = (report[0] < report[1]); 

    for (int i = 0; i < report.size() - 1; i++) {
        if ((report[i] < report[i+1]) != direction) {
            return report[i];
        } 
        if (report[i] == report[i+1]) {
            return report[i];
        } else if (abs(report[i] - report[i+1]) > 3) {
            return report[i];
        }
    }
    return -1;
}

// Solves Day 2 Part 2
int partTwo(string inputText) {
    int safeReports = 0;
    
    istringstream iss(inputText);
    string str;
    while (getline(iss, str)) {
        vector<int> report = split(str, ' ');
        bool safe = true;
        cout << "\nSTART REPORT" << endl;

        int safety = checkSafety(report, -1);
        cout << "Safety 1: " << safety << endl;

        if (safety != -1) {
            auto it = find(report.begin(), report.end(), safety);
            int vIndex = it - report.begin();

            safety = checkSafety(report, report[vIndex]);
            cout << "Safety 2: " << safety << endl;
            
            if (safety != -1) {
                safety = checkSafety(report, report[vIndex + 1]);
                cout << "Safety 3: " << safety << endl;

                if (safety != -1) {
                    safe = false;
                }
            }
        }
        safeReports += safe;
        cout << "Safe: " << safe << endl;
        cout << "safeReports: " << safeReports << endl;
    }
    cout << "Part 2: " << safeReports << "\n";
    return 1;
}