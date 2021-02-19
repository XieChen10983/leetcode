//
// Created by Laser303 on 2021/2/18.
//

#ifndef LEETCODE_2021_2_18_4_H
#define LEETCODE_2021_2_18_4_H
#include <set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool hasCycle(ListNode* head){
    if ((!head) || (!head->next))
        return false;
    set<ListNode*> s;
    while (head != nullptr){
        if (s.count(head) == 0){
            s.insert(head);
        }
        else
            return true;
        head = head->next;
    }
    return false;
}

bool hasCycle2(ListNode* head){
    if ((!head) || (!head->next))
        return false;
    ListNode* slow = head;
    ListNode* quick = head->next;
    while (slow != quick){
        if ((quick == nullptr) || (quick->next == nullptr))
            return false;
        slow = slow->next;
        quick = quick->next->next;
    }
    return true;
}
#endif //LEETCODE_2021_2_18_4_H
