#include <iostream>
#include "2021_3_3/2021_3_3_1.h"
#include <cctype>

using namespace std;

int main() {
    string s1 = "aabaac", s2 = "aadaaeaaf", s3 = "aadaaeaabaafaac", s4 = "aadbbbaccc";
    cout << isInterleave(s1, s2, s3);
    return 0;
}
