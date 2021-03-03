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
    auto* copy_ans = ans;
    stack<ListNode*> stk;
    for (int i = 1; i < left; i++)
        copy_ans = copy_ans->next;
    auto* shaobing = copy_ans->next;
    for (int i = left; i <= right; i++){
        stk.push(shaobing);
        shaobing = shaobing->next;
    }
//    copy_ans = ans->next;
    while (!stk.empty()){
        copy_ans->next = stk.top();
        copy_ans = copy_ans->next;
        stk.pop();
    }
    copy_ans->next = shaobing;
    return ans->next;
}

#endif //LEETCODE_2021_3_1_7_H
