//
// Created by Administrator on 2021/2/21.
//

#ifndef LEETCODE_2021_2_21_3_H
#define LEETCODE_2021_2_21_3_H
#include <vector>
using namespace std;

bool canJump(vector<int>& nums){
    if (nums.empty() || (nums.size() == 1))
        return true;
    if (nums[0] == 0)
        return false;
    int currentIndex = 0, nextIndex = 0;
    int maxStep;
    while (nextIndex < nums.size() - 1){
        maxStep = nums[currentIndex];
        for (int i = 1; i <= nums[currentIndex]; i++){
            if (currentIndex + i >= nums.size() - 1)
                return true;
            if (nums[currentIndex + i] + i >= maxStep){
                maxStep = nums[currentIndex + i] + i;
                nextIndex = currentIndex + i;
            }
        }
        if (currentIndex == nextIndex)
            return false;
        else
            currentIndex = nextIndex;
    }
    return true;
}

#endif //LEETCODE_2021_2_21_3_H
