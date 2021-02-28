//
// Created by Laser303 on 2021/2/24.
//

#ifndef LEETCODE_2021_2_24_1_H
#define LEETCODE_2021_2_24_1_H
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target){
    if ((nums.empty()) || (target < nums[0]) || (target > nums.back()))
        return vector<int>({-1, -1});
    if (nums.size() == 1){
        if (nums[0] == target)
            return vector<int>({0, 0});
        else
            return vector<int>({-1, -1});
    }
    if (nums.size() == 2){
        if ((nums[0] == target) && (nums[1] == target))
            return vector<int>({0, 1});
        else if (nums[0] == target)
            return vector<int>({0, 0});
        else if (nums[1] == target)
            return vector<int>({1, 1});
        else
            return vector<int>({-1, -1});
    }
    int left = 0, right = (int)nums.size() - 1, lowerbound, higherbound;
    while (left < right - 1){
        int next = (left + right) / 2;
        if (nums[next] < target)
            left = next;
        else if (nums[next] > target)
            right = next;
        else{
            lowerbound = next;
            higherbound = next;
            while(left < lowerbound - 1){
                next = (left + lowerbound) / 2;
                if (nums[next] < target)
                    left = next;
                else
                    lowerbound = next;
            }
            if (nums[left] == target)
                lowerbound = left;

            while (higherbound < right - 1){
                next = (right + higherbound) / 2;
                if (nums[next] > target)
                    right = next;
                else
                    higherbound = next;
            }
            if (nums[right] == target)
                higherbound = right;
            return vector<int>({lowerbound, higherbound});
        }
    }
    if (nums[left] == target)
        return vector<int>({left, left});
    else if (nums[right] == target)
        return vector<int>({right, right});
    else
        return vector<int>({-1, -1});
}

#endif //LEETCODE_2021_2_24_1_H
