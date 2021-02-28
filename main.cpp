#include <iostream>
#include "2021_2_25/2021_2_25_1.h"
#include <cctype>

using namespace std;


int main() {
    vector<string> out = letterCombinations("23");
    for (auto ele : out)
        cout << ele << endl;

    return 0;
}
