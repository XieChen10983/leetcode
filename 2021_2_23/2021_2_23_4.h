//
// Created by Laser303 on 2021/2/23.
//

#ifndef LEETCODE_2021_2_23_4_H
#define LEETCODE_2021_2_23_4_H

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    vector<int> level;
    queue<TreeNode*> q;
    int levelSize;
    int round = 0;
    TreeNode* currentNode;
    if (!root)
        return ans;
    q.push(root);
    while (!q.empty()){
        level.clear();
        levelSize = q.size();
        for (int i = 0; i < levelSize; i++){
            currentNode = q.front();
            level.push_back(currentNode->val);
            q.pop();
            if (currentNode->left)
                q.push(currentNode->left);
            if (currentNode->right)
                q.push(currentNode->right);
        }
        if (round % 2 == 1)
            reverse(level.begin(), level.end());
        ans.push_back(level);
        round++;
    }
    return ans;
}

#endif //LEETCODE_2021_2_23_4_H
