//
// Created by Laser303 on 2021/2/28.
//

#ifndef LEETCODE_2021_2_28_2_H
#define LEETCODE_2021_2_28_2_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k){
    ListNode* copy = head;
    ListNode* ans;
    // 计算所有节点的个数
    int count = 0;
    while (copy){
        copy = copy->next;
        count++;
    }
    int need_to_move = k % count;
    copy = head;
    for (int i = 0; i < count - need_to_move - 1; i++)
        copy = copy->next;
    ans = copy->next;
    ListNode* copy_copy = copy;
    while (copy_copy->next){
        copy_copy = copy_copy->next;
    }
    copy_copy->next = head;
    copy->next = nullptr;
    return ans;
}

#endif //LEETCODE_2021_2_28_2_H
