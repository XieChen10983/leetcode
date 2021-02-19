//
// Created by Laser303 on 2021/2/19.
//

#ifndef LEETCODE_2021_2_19_2_H
#define LEETCODE_2021_2_19_2_H
#include <vector>
using namespace std;

int zuhe(int larger, int smaller){
    if ((smaller == 0) || (larger == smaller))
        return 1;
    if (smaller == 1)
        return larger;
    int sum = 1;
    if (larger < 2 * smaller)
        smaller = larger - smaller;
    int smaller_copy = smaller;
    while (smaller > 0){
        sum *= larger--;
        smaller--;
    }
    for (int i = 1; i <= smaller_copy; i++){
        sum /= i;
    }
    return sum;
}

vector<int> getRow(int rowIndex){
    vector<int> ans;
    long long base = 1;
    ans.push_back(base);
    for (int i = 1; i <= rowIndex; i++){
        base *= (rowIndex - i + 1);
        base /= i;
        ans.push_back(base);
    }
    return ans;
}

#endif //LEETCODE_2021_2_19_2_H
