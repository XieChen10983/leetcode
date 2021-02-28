//
// Created by Laser303 on 2021/2/24.
//

#ifndef LEETCODE_2021_2_24_2_H
#define LEETCODE_2021_2_24_2_H
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists){
    if (lists.empty())
        return nullptr;
    bool flag = false;
    for (const auto& node : lists){
        if (node != nullptr){
            flag = true;
            break;
        }
    }
    if (!flag)
        return nullptr;
    auto ans = new ListNode(0);
    auto copy = ans;
    ListNode* currentSmallest;
    int smallestIndex = 0;
    while (flag){
        flag = false;
        currentSmallest = new ListNode(INT_MAX); //INT_MAX
        for (int i = 0; i < lists.size(); i++){
            flag = flag || lists[i];
            if (lists[i] != nullptr) {
                if (lists[i]->val < currentSmallest->val) {
                    currentSmallest = lists[i];
                    smallestIndex = i;
                }
            }
        }
        if (!flag)
            return ans->next;
        copy->next = currentSmallest;
        copy = copy->next;
        lists[smallestIndex] = lists[smallestIndex]->next;
    }
    return ans->next;
}

#endif //LEETCODE_2021_2_24_2_H
