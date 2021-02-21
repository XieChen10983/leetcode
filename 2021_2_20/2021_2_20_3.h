//
// Created by Administrator on 2021/2/20.
//

#ifndef LEETCODE_2021_2_20_3_H
#define LEETCODE_2021_2_20_3_H
//using namespace std;
#include <vector>

using namespace std;

uint32_t reverseBits(uint32_t n) {
    int a[32] = {0,};
    int index = 0;
    while (n != 0){
        a[index++] = n % 2;
        n /= 2;
    }
    uint32_t sum = 0;
    int base = 1;
    for (int i = 31; i >= 0; i--){
        sum += a[i] * base;
        base *= 2;
    }
    return sum;
}

#endif //LEETCODE_2021_2_20_3_H
