//
// Created by Laser303 on 2021/2/25.
//

#ifndef LEETCODE_2021_2_25_2_H
#define LEETCODE_2021_2_25_2_H

struct ListNode {
    int val;
    ListNode *next{};
    explicit ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node){
    node->val = node->next->val;
    node->next = node->next->next;
}

#endif //LEETCODE_2021_2_25_2_H
