//
// Created by Laser303 on 2021/2/19.
//

#ifndef LEETCODE_2021_2_19_1_H
#define LEETCODE_2021_2_19_1_H
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows){
    vector<vector<int>> ans;
    if (numRows == 0)
        return ans;
    if (numRows == 1)
        ans.push_back(vector<int>({1}));
    else if (numRows == 2){
        ans.push_back(vector<int>({1}));
        ans.push_back(vector<int>({1, 1}));
    }
    else{
        ans.push_back(vector<int>({1}));
        vector<int> base = {1, 1};
        vector<int> newRow;
        ans.push_back(base);
        for (int i = 2; i < numRows; i++){
            newRow.reserve(i + 1);
            newRow.push_back(1);
            for (int j = 1; j < i; j++)
                newRow.push_back(base[j - 1] + base[j]);
            newRow.push_back(1);
            ans.push_back(newRow);
            base = newRow;
            newRow.clear();
        }
    }
    return ans;
}

#endif //LEETCODE_2021_2_19_1_H
