//
// Created by Laser303 on 2021/2/17.
//

#ifndef LEETCODE_2021_2_17_5_H
#define LEETCODE_2021_2_17_5_H
#include <map>
#include <vector>
using namespace std;

string intToRoman(int num){
    vector<int> v1 = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}, v;
    vector<string> v2 = {"M", "CM", "D", "CD", "C", "CX", "L", "XL", "X", "IX", "V", "IV", "I"};

    v.reserve(13);
    for (int index = 0; index < 13; index++){
        v.push_back(num / v1[index]);
        num %= v1[index];
    }
//
//    for (int i = 0; i < v.size(); i++){
//        cout << v[i] << ": " << v1[i] << endl;
//    }
//
    string s;
    for (int j = 0; j < 13; j++){
        for (int i = 0; i < v[j]; i++){
            s += v2[j];
        }
    }
    return s;
}
#endif //LEETCODE_2021_2_17_5_H
