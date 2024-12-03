#include <cctype>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Solves Day 3 Part 1
int partOne(string inputText) {
    int total = 0;
    istringstream iss(inputText);
    string str;
    while (getline(iss, str)) {
        // probably a better way to do this than regex, but idk ¯\_(ツ)_/¯
        regex r("mul\\((\\d+),(\\d+)\\)");  
        for (sregex_iterator i = sregex_iterator(str.begin(), str.end(), r); 
            i != sregex_iterator(); 
            ++i) {
            smatch m = *i;
            total += stoi(m[1]) * stoi(m[2]);
        }    
    }
    return total;
}

// Solves Day 3 Part 2
int partTwo(string inputText) {
    int total = 0;
    istringstream iss(inputText);
    string str = "";
    string line;
    while (getline(iss, line)) {
        str = str + line;
    }
    bool proceed = true;
    regex r(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))"); 
    for (sregex_iterator i = sregex_iterator(str.begin(), str.end(), r);
        i != sregex_iterator();
        ++i) {
        smatch m = *i;

        if (m[1].matched && m[2].matched) { 
            if (proceed) {
                total += stoi(m[1]) * stoi(m[2]);
            }
        } else if (m[0] == "do()") { 
            proceed = true;
        } else if (m[0] == "don't()") { 
            proceed = false;
        }
    }
    return total;
}

// Solves Day 3 Part 1
int partOneDumb(string inputText) {
    int total = 0;
    istringstream iss(inputText);
    string str = "";
    string line;
    while (getline(iss, line)) {
        str = str + line;
    }
    for (int i = 0; i < str.size(); i++) { 
        if (str[i] == 'm' &&
            str[i+1] == 'u' &&
            str[i+2] == 'l' &&
            str[i+3] == '(') {
            int j = i+4;
            string tmpInt;
            while (str[j] != ',') {
                if (!isdigit(str[j])) {
                    goto end_loops;
                }
                tmpInt += str[j];
                j++;
            }
            int n1 = stoi(tmpInt);
            tmpInt = "";
            j++;
            while (str[j] != ')') {
                if (!isdigit(str[j])) {
                    goto end_loops;
                }
                tmpInt += str[j];
                j++;
            }
            int n2 = stoi(tmpInt); 
            total += n1 * n2;
        }
        end_loops:
    }
    return total;
}

// Solves Day 3 Part 2
int partTwoDumb(string inputText) {
    int total = 0;
    istringstream iss(inputText);
    string str = "";
    string line;
    while (getline(iss, line)) {
        str = str + line;
    }
    bool proceed = true;
    for (int i = 0; i < str.size(); i++) { 
        if (str[i] == 'd' && 
            str[i+1] == 'o' &&
            str[i+2] == 'n' &&
            str[i+3] == '\'' &&
            str[i+4] == 't' &&
            str[i+5] == '(' && 
            str[i+6] == ')') {

            proceed = false;
        } 
        if (str[i] == 'd' && 
            str[i+1] == 'o' &&
            str[i+2] == '(' &&
            str[i+3] == ')') {

            proceed = true;
        }
        if (proceed &&
            str[i] == 'm' &&
            str[i+1] == 'u' &&
            str[i+2] == 'l' &&
            str[i+3] == '(') {
            int j = i+4;
            string tmpInt;
            while (str[j] != ',') {
                if (!isdigit(str[j])) {
                    goto end_loops;
                }
                tmpInt += str[j];
                j++;
            }
            int n1 = stoi(tmpInt);
            tmpInt = "";
            j++;
            while (str[j] != ')') {
                if (!isdigit(str[j])) {
                    goto end_loops;
                }
                tmpInt += str[j];
                j++;
            }
            int n2 = stoi(tmpInt); 
            total += n1 * n2;
        }
        end_loops:
    }
    return total;
}
