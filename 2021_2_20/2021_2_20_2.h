//
// Created by Administrator on 2021/2/20.
//

#ifndef LEETCODE_2021_2_20_2_H
#define LEETCODE_2021_2_20_2_H
using namespace std;
/*
 * 126, 125*1 25*5, 5*25,
 * 76 25*3 5*15
 */


int trailingZeroes(int n) {

    if (abs(n) < 5)
        return 0;
    int ans = 0;
    int base;
    for (int i = 5; i <= n; i++){
        base = 5;
        if (i % base == 0){
            while (i % base == 0){
                ans += 1;
                base *= 5;
            }
        }
    }
    return ans;
}

int trailingZeroes2(int n) {

    int ans = 0;
    long long n_ = n;
    int base = 5;
    while (n_ >= base){
        ans += (int)n_ / base;
        base *= 5;
    }
    return ans;
}
#endif //LEETCODE_2021_2_20_2_H
