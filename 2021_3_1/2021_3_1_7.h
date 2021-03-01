//
// Created by Laser303 on 2021/3/1.
//

#ifndef LEETCODE_2021_3_1_7_H
#define LEETCODE_2021_3_1_7_H
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right){
    auto* ans = new ListNode(1);
    ans->next = head;
    auto*
    stack<ListNode*> stk;
    for (int i = 1; i < left; i++)
        head = head->next;
    auto* shaobing = head;
    for (int i = left; i < right; i++){
        stk.push(head);
        head = head->next;
    }
    return ans;
}

#endif //LEETCODE_2021_3_1_7_H
