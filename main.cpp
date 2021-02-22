#include <iostream>
#include "2021_2_22/2021_2_22_3.h"
#include <cctype>

using namespace std;


int main() {
    vector<int> nums = {0, 0, 0, 2, 4, 0, 8, 7, 6, 0, 7, 0, 7, 9, 1, 3, 7, 0, 0};
    vector<int> nums2 = {2, 3, -2, 4};
    cout << maxProduct(nums2);
//    cout << maxProductNoZeros(nums2) << endl;
    return 0;
}
