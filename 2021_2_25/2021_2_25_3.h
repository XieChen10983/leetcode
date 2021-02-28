//
// Created by Laser303 on 2021/2/25.
//

#ifndef LEETCODE_2021_2_25_3_H
#define LEETCODE_2021_2_25_3_H
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
    vector<bool> used;
public:
    void dfs(vector<vector<int>>& ans, vector<int>& permutation, int index, vector<int>& nums){
        if (index == nums.size()){
            ans.emplace_back(permutation);
            return;
        }
        for (int i = 0; i < nums.size(); ++i){
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && (!used[i - 1])))
                continue;
            permutation.push_back(nums[i]);
            used[i] = true;
            dfs(ans, permutation, index + 1, nums);
            used[i] = false;
            permutation.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums){
        int len = nums.size();
        vector<vector<int>> ans;
        if (len == 0)
            return ans;

        sort(nums.begin(), nums.end());
        used.resize(nums.size());
        vector<int> permutation;
        dfs(ans, permutation, 0, nums);
        return ans;
    }
};


//void dfs(vector<vector<int>>& ans, vector<int>& permutation, int index, vector<int>& used, vector<int>& nums){
//    if (index == nums.size()){
//        ans.emplace_back(permutation);
//        return;
//    }
//    for (int i = 0; i < len; ++i){
//        if (used[i] || (i > 0 || nums[i] == nums[i - 1] && (!used[i - 1])))
//            continue;
//        permutation.push_back(nums[i]);
//        used[i] = true;
//        dfs(ans, permutation, index + 1, len, used, nums);
//        used[i] = false;
//        permutation.pop_back();
//    }
//}
//
//vector<vector<int>> permuteUnique(vector<int>& nums){
//    int len = nums.size();
//    vector<vector<int>> ans;
//    if (len == 0)
//        return ans;
//
//    sort(nums.begin(), nums.end());
//    vector<bool> used(len, false);
//    vector<int> permutation;
//    dfs(ans, permutation, 0, used, nums);
//    return ans;
//}

#endif //LEETCODE_2021_2_25_3_H
