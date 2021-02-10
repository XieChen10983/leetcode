//
// Created by Administrator on 2021/2/8.
//

#ifndef LEETCODE_2021_2_8_2_H
#define LEETCODE_2021_2_8_2_H
#include <string>
using namespace std;

string addChar(char a, char b, char c){
    if ((a == '0') && (b == '0') && (c == '0'))
        return "00";
    else if (((a == '0') && (b == '1') && (c == '0')) || ((a == '1') && (b == '0') && (c == '0')) || ((a == '0') && (b == '0') && (c == '1')))
        return "01";
    else if (((a == '1') && (b == '1') && (c == '0')) || ((a == '1') && (b == '0') && (c == '1')) || ((a == '0') && (b == '1') && (c == '1')))
        return "10";
    else
        return "11";
}

string addBinary(string a, string b){
    int size_a = a.size();
    int size_b = b.size();
    int maxSize = size_a >= size_b ? size_a - size_b : size_b - size_a;
    string begin;
    for (int i = 0; i < maxSize; i++){
        begin += "0";
    }
    if (size_a < size_b)
        a = begin + a;
    else if (size_b < size_a)
        b = begin + b;
    else
        ;
    string res;
    string add;
    char jinzhi = '0';
    for (int i = (int)a.size() - 1; i >= 0; i--){
        add = addChar(a[i], b[i], jinzhi);
        jinzhi = add[0];
        res = add[1] + res;
    }
    if (jinzhi == '0')
        return res;
    else
        return jinzhi + res;
}

#endif //LEETCODE_2021_2_8_2_H
