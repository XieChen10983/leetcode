//
// Created by Administrator on 2021/2/20.
//

#ifndef LEETCODE_2021_2_20_5_H
#define LEETCODE_2021_2_20_5_H

int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n != 0){
        if (n % 2 == 1)
            ans++;
        n /= 2;
    }
    return ans;
}

#endif //LEETCODE_2021_2_20_5_H
