//
// Created by Laser303 on 2021/2/19.
//

#ifndef LEETCODE_2021_2_19_10_H
#define LEETCODE_2021_2_19_10_H
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target){
    vector<int> ans;
    int left_former = 0, left_latter = 0, right_former = (int)numbers.size() - 1, right_latter = (int)numbers.size() - 1;
    while (numbers[left_former] + numbers[right_former] != target){
        while (numbers[left_former] + numbers[right_former] < target)
            left_former++;
        while (numbers[left_former] + numbers[right_former] > target)
            right_former--;
    }
    ans.push_back(left_former + 1);
    ans.push_back(right_former + 1);
    return ans;
}
#endif //LEETCODE_2021_2_19_10_H
