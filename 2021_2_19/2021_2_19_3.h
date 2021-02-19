//
// Created by Laser303 on 2021/2/19.
//

#ifndef LEETCODE_2021_2_19_3_H
#define LEETCODE_2021_2_19_3_H
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices){
    int max_pro = 0;
    unsigned int size_ = prices.size();
    if ((size_ == 0) || (size_ == 1))
        return 0;
//    unsigned int min_index = 0;
    int min_ = prices[0];
    for (int i = 1; i < size_; i++){
        if (prices[i] < min_)
            min_ = prices[i];
        else
            max_pro = max(max_pro, prices[i] - min_);
    }
    return max_pro;
}

#endif //LEETCODE_2021_2_19_3_H
