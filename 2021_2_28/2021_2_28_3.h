//
// Created by Laser303 on 2021/2/28.
//

#ifndef LEETCODE_2021_2_28_3_H
#define LEETCODE_2021_2_28_3_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeHeadDuplicate(ListNode* head){
    if (!head)
        return nullptr;
    if (!head->next)
        return head;
    if (head->val != head->next->val)
        return head;
    int currrentVal = head->val;
    while ((head != nullptr) && (head->val == currrentVal))
        head = head->next;
    if (head == nullptr)
        return nullptr;
    return removeHeadDuplicate(head);
}

ListNode* deleteDuplicates(ListNode* head){
    if ((!head) || (!head->next))
        return head;

    // 找到第一个非重复的节点
    head = removeHeadDuplicate(head);

    ListNode* ans = head;
    ListNode* ansCopy = ans;
    if (!ans)
        return nullptr;
    while (head->next){
        head = removeHeadDuplicate(head->next);
        ansCopy->next = head;
        ansCopy = ansCopy->next;
        if (!head)
            break;
    }
    return ans;
//    ListNode* left = head->next;
//    if (!left)
//        return head;
//    ListNode* right = left->next;
//    if (!right)
//        return head;
//    while (right){
//        if (left->val != right->val){
//            head = left;
//            left = right;
//            right = right->next;
//        }
//        else{
//            int currentVal = left->val;
//            while (left && (left->val == currentVal))
//                left = left->next;
//            head->next = left;
//            if (left->next)
//                left->next = right;
//            else
//                right = nullptr;
//        }
//    }
    return ans;
}

#endif //LEETCODE_2021_2_28_3_H
