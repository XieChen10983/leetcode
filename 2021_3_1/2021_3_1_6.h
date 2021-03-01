//
// Created by Laser303 on 2021/3/1.
//

#ifndef LEETCODE_2021_3_1_6_H
#define LEETCODE_2021_3_1_6_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x){
    auto* smaller = new ListNode(0);
    auto* larger = new ListNode(0);
    ListNode* smaller_copy = smaller;
    ListNode* larger_copy = larger;
    while (head != nullptr){
        if (head->val < x){
            smaller->next = head;
            smaller = smaller->next;
        }
        else{
            larger->next = head;
            larger = larger->next;
        }
        head = head->next;
    }
    larger->next = nullptr;
    smaller->next = larger_copy->next;
    return smaller_copy->next;
}

#endif //LEETCODE_2021_3_1_6_H
