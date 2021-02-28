//
// Created by Laser303 on 2021/2/23.
//

#ifndef LEETCODE_2021_2_23_2_H
#define LEETCODE_2021_2_23_2_H
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

int addVector(const vector<int>& v){
    int sum = 0;
    for (int i : v){
        sum = sum * 10 + i;
    }
    return sum;
}

void dfs(TreeNode* root, vector<int> path, int& sum){
    if (!root)
        return;
    path.push_back(root->val);
    if ((!root->left) && (!root->right)){
        sum += addVector(path);
    }
    dfs(root->left, path, sum);
    dfs(root->right, path, sum);
    path.pop_back();
}

//int sum = 0;
////int pathSum = 0;
//vector<int> path;


int sumNumbers(TreeNode* root){
    if (!root)
        return 0;
    if (root->val == 0)
        return sumNumbers(root->left) + sumNumbers(root->right);
    int sum = 0;
    vector<int> path;
    dfs(root, path, sum);
    return sum;
}

#endif //LEETCODE_2021_2_23_2_H
