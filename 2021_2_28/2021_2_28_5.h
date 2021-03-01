//
// Created by Laser303 on 2021/2/28.
//

#ifndef LEETCODE_2021_2_28_5_H
#define LEETCODE_2021_2_28_5_H
#include <vector>
using namespace std;

int largestRectangleArea(vector<int>& heights){
    if (heights.empty())
        return 0;
    if (heights.size() == 1)
        return heights[0];
    int ans = heights[0];
    int min = ans;
    for (int i = 1; i < heights.size(); i++){
        
    }
}

#endif //LEETCODE_2021_2_28_5_H
