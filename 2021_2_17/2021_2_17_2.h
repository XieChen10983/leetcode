//
// Created by Laser303 on 2021/2/17.
//

#ifndef LEETCODE_2021_2_17_2_H
#define LEETCODE_2021_2_17_2_H
#include <string>
#include <map>
#include <cmath>
using namespace std;
static map<char, int> m = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4},
                           {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}};

int myAtoi(string s){
    if (s.empty())
        return 0;
    int index = 0;

    // 取出前导空格
    while ((index < s.size()) && (s[index] == ' '))
        index++;
    s = s.substr(index, s.size());
    if (s.empty())
        return 0;

    // 判断是否有正负号，zhengfu表明正负号，s为去除正负号之后的字符串
    int zhengfu = 1;
    if ((s[0] != '-') && (s[0] != '+') && (m.count(s[0]) == 0))
        return 0;
    else if (s[0] == '-') {
        zhengfu = -1;
        s = s.substr(1, s.size());
    }
    else if (s[0] == '+'){
        s = s.substr(1, s.size());
    }
    else
        ;

    // 提取字符, effective 存储
    string effective;
    for (const auto& c : s){
        if (m.count(c) == 1){
            effective.push_back(c);
        }
        else
            break;
    }
    index = 0;
    for (; index < effective.size(); index++){
        if (effective[index] == '0')
            continue;
        else
            break;
    }
    effective = effective.substr(index, effective.size());
    if (effective.empty())
        return 0;

    // 将有效字符转换
    long long num = 0;
    if (zhengfu == 1) {
        if (effective.size() >= 11)
            return 2147483647;
        for (int i = (int) effective.size() - 1; i >= 0; i--) {
            num += m[effective[i]] * pow(10, effective.size() - i - 1);
            if (num > pow(2, 32) - 1) {
                return 2147483647;
            }
        }
        return (int) num;
    }
    else{
        if (effective.size() >= 11)
            return -2147483648;
        for (int i = (int) effective.size() - 1; i >= 0; i--) {
            num += m[effective[i]] * pow(10, effective.size() - i - 1);
            if (num > pow(2, 32)) {
                return -2147483648;
            }
        }
        return -(int) num;
    }
}

#endif //LEETCODE_2021_2_17_2_H
