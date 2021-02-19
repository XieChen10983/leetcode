//
// Created by Laser303 on 2021/2/19.
//

#ifndef LEETCODE_2021_2_19_7_H
#define LEETCODE_2021_2_19_7_H
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

bool hasPathSum(TreeNode* root,int targetSum){
    if (!root)
        return false;
    queue<TreeNode*> nodes;
    nodes.push(root);
    TreeNode* currentNode;
    while(!nodes.empty()){
        currentNode = nodes.front();
        nodes.pop();
        if ((!currentNode->left) && (!currentNode->right)){
            if (currentNode->val == targetSum)
                return true;
        }
        else{
            if (currentNode->left != nullptr){
                currentNode->left->val += currentNode->val;
                nodes.push(currentNode->left);
            }
            if (currentNode->right != nullptr){
                currentNode->right->val += currentNode->val;;
                nodes.push(currentNode->right);
            }
        }
    }
    return false;
}

#endif //LEETCODE_2021_2_19_7_H
