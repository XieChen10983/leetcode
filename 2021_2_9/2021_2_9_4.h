//
// Created by Administrator on 2021/2/9.
//

#ifndef LEETCODE_2021_2_9_4_H
#define LEETCODE_2021_2_9_4_H
#include <vector>
#include <stack>
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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> v;
    if (!root)
        return v;
    vector<int> v1({root->val});
//    int a = v1[0];
//    int b = root->val;
    queue<TreeNode*> q;
    TreeNode* currentNode;
    vector<int> currentLayer;
    q.push(root);
//    v.push_back(v1);
    int layerNum;
    while (!q.empty()){
        layerNum = q.size();
        currentLayer.clear();
        for (int i = 0; i < layerNum; i++){
            currentNode = q.front();
            currentLayer.push_back(currentNode->val);
            q.pop();
            if (currentNode->left)
                q.push(currentNode->left);
            if (currentNode->right)
                q.push(currentNode->right);
        }
        v.push_back(currentLayer);
    }
    reverse(v.begin(), v.end());
    return v;
}

#endif //LEETCODE_2021_2_9_4_H
