//
// Created by Administrator on 2021/2/21.
//

#ifndef LEETCODE_2021_2_21_4_H
#define LEETCODE_2021_2_21_4_H

#include<vector>
using namespace std;

void printVV(const vector<vector<int>>& vv){
    for (const auto& v : vv){
        cout << "[" << v[0] << ", " << v[1] << "]" << '\t';
    }
    cout << endl;
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
    if (intervals.empty()){
        intervals.push_back(newInterval);
        return intervals;
    }
    if (newInterval[1] < intervals[0][0]){
        intervals.insert(intervals.begin(), newInterval);
        return intervals;
    }
    if (intervals[intervals.size() - 1][1] < newInterval[0]){
        intervals.push_back(newInterval);
        return intervals;
    }
    vector<vector<int>> ans;
    // 找到前例
    int leftIndex = 0, inter_min, inter_max, rightIndex;
    while (leftIndex < intervals.size()){
        if (intervals[leftIndex][1] < newInterval[0]){
            ans.push_back(intervals[leftIndex]);
            leftIndex++;
        }
        else
            break;
    }
    inter_min = min(newInterval[0], intervals[leftIndex][0]);
    rightIndex = leftIndex;
    while (leftIndex < intervals.size()){
        if (intervals[leftIndex][0] <= newInterval[1]){
            inter_max = max(newInterval[1], intervals[leftIndex][1]);
            leftIndex++;
        }
        else
            break;
    }
    if (rightIndex == leftIndex){
        ans.push_back(newInterval);
    }
    else{
        ans.push_back(vector<int> ({inter_min, inter_max}));
    }
    while (leftIndex < intervals.size()){
        ans.push_back(intervals[leftIndex]);
        leftIndex++;
    }
    return ans;
}

#endif //LEETCODE_2021_2_21_4_H
