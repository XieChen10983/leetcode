//
// Created by Laser303 on 2021/2/19.
//

#ifndef LEETCODE_2021_2_19_11_H
#define LEETCODE_2021_2_19_11_H
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string convertToTitle(int n){
    int base = 26;
    int weishu;
    if (n <= 26)
        weishu = 1;
    else{
        weishu = 2;
        while (n / base >= 26){
            base *= 26;
            weishu++;
        }
    }
    vector<int> v;
    while (weishu > 0){
        v.push_back(n / pow(26, weishu - 1));
        n = n % (int)pow(26, weishu - 1);
        weishu--;
    }

    for (const auto& ele : v)
        cout << ele << ", ";

    return "";
}

#endif //LEETCODE_2021_2_19_11_H
