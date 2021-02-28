//
// Created by Laser303 on 2021/2/23.
//

#ifndef LEETCODE_2021_2_23_1_H
#define LEETCODE_2021_2_23_1_H

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> ans;
vector<int> path;

void dfs(TreeNode* root, int sum){
    if (root == nullptr)
        return;
    path.emplace_back(root->val);
    sum -= root->val;
    if ((!root->left) && (!root->right) && (sum == 0))
        ans.emplace_back(path);
    dfs(root->left, sum);
    dfs(root->right, sum);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    dfs(root, sum);
    return ret;
}

#endif //LEETCODE_2021_2_23_1_H
