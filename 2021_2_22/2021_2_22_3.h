//
// Created by Laser303 on 2021/2/22.
//

#ifndef LEETCODE_2021_2_22_3_H
#define LEETCODE_2021_2_22_3_H
#include <vector>
using namespace std;

int maxProductNoZeros(vector<int>& nums){
    vector<int> minusIndex;
    for (int index = 0; index < nums.size(); index++){
        if (nums[index] < 0)
            minusIndex.push_back(index);
    }
    int ans = 1;
    if (minusIndex.size() % 2 == 0){
        for (const auto& num : nums)
            ans *= num;
        return ans;
    }

    else if (minusIndex.size() == 1){
        if (minusIndex[0] == 0){
            for (int i = 1; i < nums.size(); i++)
                ans *= nums[i];
            return ans;
        }
        else if (minusIndex[0] == nums.size() - 1){
            for (int i = 0; i < nums.size() - 1; i++)
                ans *= nums[i];
            return ans;
        }
        else{
            int left = 1, right = 1;
            for (int i = 0; i < minusIndex[0]; i++)
                left *= nums[i];
            for (int j = minusIndex[0] + 1; j < nums.size(); j++){
                right *= nums[j];
            }
            return max(left, right);
        }
    }

    else{
        int left = 1, right = 1;
        int left_index = 0, right_index = (int)nums.size() - 1;
        while ((left_index < nums.size()) && (nums[left_index] > 0)){
            left *= nums[left_index];
            left_index++;
        }
        left *= nums[left_index];

        while ((right_index >= 0) && (nums[right_index] > 0)){
            right *= nums[right_index];
            right_index--;
        }
        right *= nums[right_index];

        if (left > right){
            while (right_index > left_index + 1){
                right_index--;
                right *= nums[right_index];
            }
            return right;
        }
        else{
            while (left_index < right_index - 1){
                left_index++;
                left *= nums[left_index];
            }
            return left;
        }
    }
}

int maxProduct(vector<int>& nums){
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];
    vector<int> subVector;
    vector<vector<int>> v;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] == 0)
            continue;
        else{
            while ((i < nums.size()) && (nums[i] != 0)){
                subVector.push_back(nums[i]);
                i++;
            }
            v.push_back(subVector);
            subVector.clear();
        }
    }

//    for (const auto& ve : v){
//        for (const auto& ele : ve)
//            cout << ele << '\t';
//        cout << endl;
//    }

    if (v.empty())
        return 0;
    else if (v.size() == 1)
        return maxProductNoZeros(v[0]);
    else{
        int max_ = maxProductNoZeros(v[0]);
        for (int i = 1; i < v.size(); i++){
            max_ = max(max_, maxProductNoZeros(v[i]));
        }
        return max_;
    }
//    return 1;
}

#endif //LEETCODE_2021_2_22_3_H
