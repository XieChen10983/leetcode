//
// Created by Administrator on 2021/2/20.
//
// 1. EXCEL表序号A->1, B->2,..., AA->27
#ifndef LEETCODE_2021_2_20_1_H
#define LEETCODE_2021_2_20_1_H
#include <string>

using namespace std;

int titleToNumber(string s){
    int ans = 0;
    int k = 1;
    for (int index = (int)s.size() - 1; index >= 0; index--){
        ans += (s[index] - 'A' + 1) * k;
        k *= 26;
    }
    return ans;
}

#endif //LEETCODE_2021_2_20_1_H
