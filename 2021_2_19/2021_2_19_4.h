//
// Created by Laser303 on 2021/2/19.
//

#ifndef LEETCODE_2021_2_19_4_H
#define LEETCODE_2021_2_19_4_H
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices){
    size_t size = prices.size();
    if ((size == 0) || (size == 1))
        return 0;
    int sumProfit = 0;
    int currentIndex = 1;
    int minIndex, maxIndex;
    while(currentIndex < size){
//        minIndex = currentIndex;
        while((currentIndex < size) && (prices[currentIndex] <= prices[currentIndex - 1])){
            currentIndex++;
        }
        minIndex = currentIndex - 1;
//        if(minIndex == size - 1)
//            return 0;
        while ((currentIndex < size) && (prices[currentIndex] >= prices[currentIndex - 1]))
            currentIndex++;
        maxIndex = currentIndex - 1;
        sumProfit += prices[maxIndex] - prices[minIndex];
    }
    return sumProfit;
}
#endif //LEETCODE_2021_2_19_4_H
