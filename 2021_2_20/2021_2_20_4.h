//
// Created by Administrator on 2021/2/20.
//

#ifndef LEETCODE_2021_2_20_4_H
#define LEETCODE_2021_2_20_4_H
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

bool bigger(int a, int b){
//    cout << "----------------------------------------------" << endl;
//    cout << "comparing " << a << " and " << b << endl;
    if (a == 0)
        return false;
    if (b == 0)
        return true;
    long long compare = 1;
    int a_wei = 0, b_wei = 0;
    while (compare <= a){
        compare *= 10;
        a_wei++;
    }
    compare = 1;
    while (compare <= b){
        compare *= 10;
        b_wei++;
    }
//    cout << "former: " << a*pow(10, b_wei) + b << "  latter: " << b*pow(10, a_wei) + a << endl;
    return (a*pow(10, b_wei) + b) >= (b*pow(10, a_wei) + a);
}

string largestNumber(vector<int>& nums) {
//    for (const auto& ele : nums)
//        cout << ele << "  ";
//    cout << endl;
    sort(nums.begin(), nums.end(), bigger);
    for (const auto& ele : nums)
        cout << ele << "  ";
    cout << endl;
    string ans;
    stack<char> stk;
    for (auto ele : nums){
        if (ele == 0){
            ans += '0';
        }
        while (ele != 0){
            stk.push((char)(ele % 10 + '0'));
            ele /= 10;
        }
        while (!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
    }
    return ans;
}

#endif //LEETCODE_2021_2_20_4_H
