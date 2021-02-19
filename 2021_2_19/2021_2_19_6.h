//
// Created by Laser303 on 2021/2/19.
//

#ifndef LEETCODE_2021_2_19_6_H
#define LEETCODE_2021_2_19_6_H


struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int minDepth(TreeNode* root){
    if (!root)
        return 0;
    if ((!root->left) && (!root->right))
        return 1;
    if (!root->left)
        return 1 + minDepth(root->right);
    else if (!root->right)
        return 1 + minDepth(root->left);
    else
        return 1 + min(minDepth(root->left), minDepth(root->right));
}

#endif //LEETCODE_2021_2_19_6_H
