//
// Created by Administrator on 2021/2/20.
//

#ifndef LEETCODE_2021_2_20_7_H
#define LEETCODE_2021_2_20_7_H

double myPow2(double x, int n){
    if (n == 0)
        return 1;
    if (x == 1)
        return 1;
    if (x == -1)
        return n % 2 == 0 ? 1 : -1;
    //TODO
}

double myPow(double x, int n) {
    if (n == 0)
        return 1;
    int abs_n = n > 0 ? n : -n;
    double ans = 1;
    for (int i = 0; i < abs_n; i++)
        ans *= x;
    if (n < 0)
        return 1 / ans;
    else
        return ans;
}

#endif //LEETCODE_2021_2_20_7_H
