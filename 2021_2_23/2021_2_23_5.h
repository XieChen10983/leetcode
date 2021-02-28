//
// Created by Laser303 on 2021/2/23.
//

#ifndef LEETCODE_2021_2_23_5_H
#define LEETCODE_2021_2_23_5_H
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


Node* connect(Node* root) {
    if ((!root) || ((!root->left) || (!root->right)))
        return root;
    Node* leftMost = root;
    Node* currentNode;
    while (leftMost){
        currentNode = leftMost;
        while (currentNode){
            if (currentNode->left){
                if (currentNode->right)
                    currentNode->left->next = currentNode->right;
            }
            if (currentNode->right){
                if (currentNode->next)
                    currentNode->right->next = currentNode->next->left;
            }
            currentNode = currentNode->next;
        }
        leftMost = leftMost->left;
    }
    return root;
}

#endif //LEETCODE_2021_2_23_5_H
