//
// Created by Administrator on 2021/2/9.
//

#ifndef LEETCODE_2021_2_9_3_H
#define LEETCODE_2021_2_9_3_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root) {
    if (!root)
        return 0;
    if ((!root->left) && (!root->right))
        return 1;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
#endif //LEETCODE_2021_2_9_3_H
