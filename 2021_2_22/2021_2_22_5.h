//
// Created by Laser303 on 2021/2/22.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#ifndef LEETCODE_2021_2_22_5_H
#define LEETCODE_2021_2_22_5_H
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> recur(TreeNode* root, int targetSum){
    while ((root->left) || (root->right)){

    }
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum){
    vector<vector<int>> ans;
    if (!root)
        return ans;
    if ((!root->left) && (!root->right)){
        if (root->val == targetSum)
            ans.emplace_back(targetSum);
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* currentNode;
    while (!q.empty()){
        currentNode = q.pop();
        if (currentNode->left){
            currentNode->left->val += currentNode->val;
            q.push(currentNode->left);
        }
        if (currentNode->right){
            currentNode->right->val += currentNode->val;
            q.push(currentNode->right);
        }
        if ((!currentNode->left) && (!currentNode->right)){
            if (currentNode->val == targetSum){
                ;
            }
            else
                continue;
        }
        else
            continue;
    }
}

#endif //LEETCODE_2021_2_22_5_H
