//
// Created by Laser303 on 2021/2/25.
//

#ifndef LEETCODE_2021_2_25_1_H
#define LEETCODE_2021_2_25_1_H
#include <vector>
using namespace std;

//void backTrack(vector<vector<int>>& permutations, vector<int>& permutation, int first, int len){
//    if (first == len){
//        permutations.emplace_back(permutation);
//        return;
//    }
//
//    for (int i = first; i < len; ++i){
//        swap(permutation[i], permutation[first]);
//        backTrack(permutations, permutation, first + 1, len);
//        swap(permutation[i], permutation[first]);
//    }
//
//}
//
//vector<vector<int>> permute(vector<int>& nums){
//    vector<vector<int>> ans;
////    vector<int> v;
//    backTrack(ans, nums, 0, nums.size());
//    return ans;
//}

void dfs(vector<int> nums, int len, int depth, vector<int>& path, vector<bool> used, vector<vector<int>>& res){
    if (depth == len){
        res.push_back(path);
        return;
    }

    for (int i = 0; i < len; i++){
        if (used[i])
            continue;
        path.push_back(nums[i]);
        used[i] = true;
        dfs(nums, len, depth+1, path, used, res);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int> nums){
    int len = nums.size();
    vector<vector<int>> res;
    if (len == 0)
        return res;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    dfs(nums, len, 0, path, used, res);
    return res;
}

#endif //LEETCODE_2021_2_25_1_H
