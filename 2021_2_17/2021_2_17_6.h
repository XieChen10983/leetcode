//
// Created by Laser303 on 2021/2/17.
//

#ifndef LEETCODE_2021_2_17_6_H
#define LEETCODE_2021_2_17_6_H
#include <vector>
#include <algorithm>
using namespace std;



vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> ans;
    if (nums.size() <= 2)
        return ans;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    int index = 0;
    int left, right;
    while (index < size - 2){
//        while ((index < size - 2) && (nums[index] == nums[index + 1])){
//            index++;
//        } // 去重

        if ((index > 0) && (nums[index] == nums[index - 1])){
            index++;
            continue;
        }

        left = index + 1;
        right = size - 1;
        while (left < right){
            if (nums[index] + nums[left] + nums[right] > 0){
                right--;
            }
            else if (nums[index] + nums[left] + nums[right] < 0){
                left++;
            }
            else{
                ans.push_back(vector<int>({nums[index], nums[left], nums[right]}));
                while ((left < right) && (nums[left] == nums[left + 1])){
                    left += 1;
                }
                while ((left < right) && (nums[right] == nums[right - 1])){
                    right -= 1;
                }
                left++;
                right--;
            }
        }

        index++;
    }
    return ans;
//TODO
}
#endif //LEETCODE_2021_2_17_6_H
