//
// Created by Laser303 on 2021/2/19.
//

#ifndef LEETCODE_2021_2_19_5_H
#define LEETCODE_2021_2_19_5_H
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string s){
    if (s.empty() || s.size() == 1)
        return true;
    int left = 0, right = (int)s.size() - 1;
    while(right - left >= 1){
        while ((!isalnum(s[left])) && (right - left >= 1))
            left++;
        while ((!isalnum(s[right])) && (right - left >= 1))
            right--;
        if (tolower(s[left]) != tolower(s[right]))
            return false;
        left++;
        right--;
    }
    return true;
}
#endif //LEETCODE_2021_2_19_5_H
