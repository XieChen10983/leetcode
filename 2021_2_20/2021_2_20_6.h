//
// Created by Administrator on 2021/2/20.
//

#ifndef LEETCODE_2021_2_20_6_H
#define LEETCODE_2021_2_20_6_H
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> a;
        set<ListNode*> b;
        while ((headA != nullptr) || (headB != nullptr)){
            if (headA != nullptr){
                if (b.count(headA) == 1)
                    return headA;
                else
                    a.insert(headA);
                headA = headA->next;
            }
            if (headB != nullptr){
                if (a.count(headB) == 1)
                    return headB;
                else
                    b.insert(headB);
                headB = headB->next;
            }
        }
        return headB;
    }
};

#endif //LEETCODE_2021_2_20_6_H
