//
// Created by Laser303 on 2021/2/18.
//


struct ListNode {
 int val;
 ListNode *next;
 ListNode() : val(0), next(nullptr) {}
 ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#ifndef LEETCODE_2021_2_18_2_H
#define LEETCODE_2021_2_18_2_H

ListNode* swapPairs(ListNode* head){
    if (!head)
        return nullptr;
    if (!head->next)
        return head;
    auto* shaobing = new ListNode(0);
    auto* left = head;
    auto* right = head->next;
    auto* next_next = head->next->next;
    head = head->next;

    while (right){
        shaobing->next = right;
        right->next = left;
        left->next = next_next;

        shaobing = left;
        left = next_next;
        if (left){
            if (left->next)
                right = left->next;
            else
                right = nullptr;
            if (right){
                if (right->next)
                    next_next = right->next;
                else
                    next_next = nullptr;
            }
        }
        else{
            break;
        }
    }
    return head;
}

#endif //LEETCODE_2021_2_18_2_H
