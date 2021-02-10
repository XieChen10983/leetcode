//
// Created by Administrator on 2021/2/9.
//

#ifndef LEETCODE_2021_2_9_2_H
#define LEETCODE_2021_2_9_2_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSymmetric(TreeNode* root1, TreeNode* root2){
    if ((!(root1)) && (!(root2)))
        return true;
    if (((bool)root1 ^ (bool)root2))
        return false;
    if (root1->val != root2->val)
        return false;
    if (((root1->left == nullptr) && (root2->right != nullptr)) || ((root1->right == nullptr) && (root2->left != nullptr)) ||
            ((root2->left == nullptr) && (root1->right != nullptr)) || ((root2->right == nullptr) && (root1->left != nullptr)))
        return false;
    else
        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
}


bool isSymmetric(TreeNode* root) {
    if (!root)
        return true;
    if (((bool)root->left ^ (bool)root->right))
        return false;
//    if ((root->left))
    return isSymmetric(root->left, root->right);
}

#endif //LEETCODE_2021_2_9_2_H
