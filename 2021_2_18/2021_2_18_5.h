//
// Created by Laser303 on 2021/2/18.
//

#ifndef LEETCODE_2021_2_18_5_H
#define LEETCODE_2021_2_18_5_H
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int recur(TreeNode* root){
    if (!root)
        return 0;
    int leftHeight = recur(root->left);
    if (leftHeight == -1)
        return -1;
    int rightHeight = recur(root->right);
    if (rightHeight == -1)
        return -1;
    if ((leftHeight - rightHeight < 2) && (leftHeight - rightHeight > -2))
        return max(leftHeight, rightHeight) + 1;
    else
        return -1;
}

bool isBalanced(TreeNode* root){
    return recur(root) != -1;
}
#endif //LEETCODE_2021_2_18_5_H
