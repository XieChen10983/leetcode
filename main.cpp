#include <iostream>
#include <map>
#include "2021_2_10/2021_2_10_1.h"

using namespace std;

int main() {
    map<char, int> m;
    string s1 = "adc";
    string s2 = "dcda";
    cout << checkInclusion(s1, s2) << endl;
    return 0;
}
