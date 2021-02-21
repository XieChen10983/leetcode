//
// Created by Laser303 on 2021/2/19.
//

#ifndef LEETCODE_2021_2_19_11_H
#define LEETCODE_2021_2_19_11_H
#include <string>
#include <vector>
#include <cmath>
using namespace std;

/*
 * 1-A 2-B ... 26-Z, 27-AA 52-AZ  676-ZZ 677-AAA
 */

string convertToTitle(int n) {
    string res;
    while (n > 0) {
        n -= 1;
        int rem = n % 26;
        res = char(rem + 'A') + res;
        n /= 26;
    }

    return res;
}

#endif //LEETCODE_2021_2_19_11_H
