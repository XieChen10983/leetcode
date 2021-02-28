//
// Created by Laser303 on 2021/2/23.
//

#ifndef LEETCODE_2021_2_23_3_H
#define LEETCODE_2021_2_23_3_H
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    vector<int> level;
    queue<TreeNode*> q;
    int levelSize;
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
        ans.push_back(level);
    }
    return ans;
}

#endif //LEETCODE_2021_2_23_3_H
