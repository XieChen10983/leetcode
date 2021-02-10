//
// Created by Administrator on 2021/2/8.
//

#ifndef LEETCODE_2021_2_8_1_H
#define LEETCODE_2021_2_8_1_H
#include <vector>
using namespace std;

int maxTurbulenceSize_(vector<int>& arr,  int pos = 0){
    if (pos >= arr.size())
        return 0;
    if (arr.size() - pos <= 2)
        return (int)arr.size() - pos;
    int maxSize = 1;
    int arrSize = arr.size();
    int even = pos, odd = pos + 1;
    int round = 0;
    if (arr[even] < arr[odd]){
        while ((arr[even] < arr[odd]) && (even < arrSize) && (odd < arrSize)){
            if (round % 2 == 0)
                even += 2;
            else
                odd += 2;
            maxSize++;
            round++;
        }
        return max(maxSize, maxTurbulenceSize_(arr, min(even, odd)));
    }
    else if (arr[even] > arr[odd]){
        while ((arr[even] > arr[odd]) && (even < arrSize) && (odd < arrSize)){
            if (round % 2 == 0)
                even += 2;
            else
                odd += 2;
            maxSize++;
            round++;
        }
        return max(maxSize, maxTurbulenceSize_(arr, min(even, odd)));
    }
    else{
        return maxTurbulenceSize_(arr, ++pos);
    }
}

int maxTurbulenceSize(vector<int>& arr){
    return maxTurbulenceSize_(arr, 0);
}

#endif //LEETCODE_2021_2_8_1_H
