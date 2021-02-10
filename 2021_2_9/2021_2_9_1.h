//
// Created by Administrator on 2021/2/9.
//

#ifndef LEETCODE_2021_2_9_1_H
#define LEETCODE_2021_2_9_1_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if ((!p) && (!q))
        return true;
    else if (((!p) && q) || ((!q) && p))
        return false;
    else{
        if (p->val != q->val)
            return false;
        else{
            return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        }
    }
}


#endif //LEETCODE_2021_2_9_1_H
