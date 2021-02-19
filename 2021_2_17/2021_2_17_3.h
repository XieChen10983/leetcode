//
// Created by Laser303 on 2021/2/17.
//

#ifndef LEETCODE_2021_2_17_3_H
#define LEETCODE_2021_2_17_3_H
#include <vector>

using namespace std;

int maxArea(vector<int>& height){
    int left = 0, right = (int)height.size() - 1;
    int max_Area = min(height[left], height[right]) * (right - left);
    int new_Area;
    while (left < right){
        if (height[left] < height[right]){
            left++;
        }
        else{
            right--;
        }
        new_Area = min(height[left], height[right]) * (right - left);
        max_Area = max(max_Area, new_Area);
    }
    return max_Area;
}

#endif //LEETCODE_2021_2_17_3_H
