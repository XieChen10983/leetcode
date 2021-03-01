//
// Created by Laser303 on 2021/3/1.
//

#ifndef LEETCODE_2021_3_1_1_H
#define LEETCODE_2021_3_1_1_H

#include <vector>
using namespace std;

void printVV(const vector<vector<int>>& vv){
    for (const auto& v : vv){
        for (const auto& ele : v){
            cout << ele << '\t';
        }
        cout << endl;
    }
}

bool searchMatrix(vector<vector<int>>& matrix, int target){
    if (matrix.empty())
        return false;
    if (matrix[0].empty())
        return false;
    int m = matrix.size(), n = matrix[0].size(), left = 0, right = m*n - 1, middle;
    if ((target < matrix[0][0]) || (target > matrix[m - 1][n - 1]))
        return false;
    while (right > left + 1){
        middle = (right + left) / 2;
        if (matrix[middle/n][middle%n] <= target)
            left = middle;
        else
            right = middle;
    }
    if ((matrix[right/n][right%n] == target) || (matrix[left/n][left%n] == target))
        return true;
    else
        return false;
}

#endif //LEETCODE_2021_3_1_1_H
