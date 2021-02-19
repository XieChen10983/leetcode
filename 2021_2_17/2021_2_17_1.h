//
// Created by Laser303 on 2021/2/17.
//

#ifndef LEETCODE_2021_2_17_1_H
#define LEETCODE_2021_2_17_1_H
#include <vector>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c){
    int initialRow = nums.size(), initialCol = nums[0].size();
    if (nums.empty())
        return nums;
    if (nums[0].empty())
        return nums;
    if (initialCol * initialRow != r * c)
        return nums;
    if (initialRow == r)
        return nums;

    vector<vector<int>> newMatrix;
    vector<int> newRow;
    newRow.reserve(c);
    for (int i = 0; i < r * c; i++){
        newRow.push_back(nums[int(i / initialCol)][i % initialCol]);
        if ((i + 1) % c == 0){
            newMatrix.push_back(newRow);
            newRow.clear();
            newRow.reserve(c);
        }
    }
    return newMatrix;
}

#endif //LEETCODE_2021_2_17_1_H
