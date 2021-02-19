//
// Created by Laser303 on 2021/2/19.
//

#ifndef LEETCODE_2021_2_19_8_H
#define LEETCODE_2021_2_19_8_H
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums){
    int ans = 0;
    for (const auto& ele : nums)
        ans ^= ele;
    return ans;
}
#endif //LEETCODE_2021_2_19_8_H
