//
// Created by Laser303 on 2021/3/3.
//

#ifndef LEETCODE_2021_3_3_2_H
#define LEETCODE_2021_3_3_2_H
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode* root){
    vector<int> ret;
    if (root == nullptr)
        return ret;
    stack<TreeNode*> stk;
    TreeNode* current = root;
    while (current != nullptr || (!stk.empty())){
        while (current != nullptr){
            stk.push(current);
            current = current->left;
        }
        current = stk.top();
        stk.pop();
        ret.push_back(current->val);
        current = current->right;
    }
    return ret;
}
#endif //LEETCODE_2021_3_3_2_H
