//
// Created by Laser303 on 2021/3/1.
//

#ifndef LEETCODE_2021_3_1_2_H
#define LEETCODE_2021_3_1_2_H

#include <vector>

using namespace std;

void sortColors(vector<int>& nums){
    if (nums.empty())
        return;
    vector<int> colorNum(3, 0);
    for (int ele : nums)
        colorNum[ele]++;
    int index = 0;
    for (; index < colorNum[0]; index++)
        nums[index] = 0;
    for (; index < colorNum[0] + colorNum[1]; index++)
        nums[index] = 1;
    for (; index < colorNum[0] + colorNum[1] + colorNum[2]; index++)
        nums[index] = 2;
}

void sortColors2(vector<int>& nums){
    if (nums.empty())
        return;
    int zeroIndex = 0, twoIndex = (int)nums.size() - 1, index = 0;
    for (int i = 0; i <= twoIndex; i++){
        while (i <= twoIndex && nums[i] == 2){
            swap(nums[i], nums[twoIndex]);
            twoIndex--;
        }
        if (nums[i] == 0){
            swap(nums[i], nums[zeroIndex]);
            zeroIndex++;
        }
    }
}

#endif //LEETCODE_2021_3_1_2_H
