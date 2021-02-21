#include <iostream>
#include "2021_2_21/2021_2_21_4.h"
#include <cctype>

using namespace std;


int main() {
//    vector<vector<int>> v = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<vector<int>> v = {{3, 5}, {12, 15}};
    printVV(v);
    vector<int> newinter = {6, 6};
    vector<vector<int>> out = insert(v, newinter);
    printVV(out);
    return 0;
}
