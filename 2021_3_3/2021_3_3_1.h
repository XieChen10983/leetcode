//
// Created by Laser303 on 2021/3/3.
//

#ifndef LEETCODE_2021_3_3_1_H
#define LEETCODE_2021_3_3_1_H

#include <string>
using namespace std;

bool isInterleave(string s1, string s2, string s3){
    if ((s1 + s2 == s3) || (s2 + s1 == s3))
        return true;
    if (s1.empty() || s2.empty())
        return false;
    string subString1, subString2;
    if ((s1[0] != s3[0]) && (s2[0] != s3[0]))
        return false;
    else if ((s1[0] != s3[0]) && (s2[0] == s3[0])){
        subString1 = s2.substr(1, s2.size());
        subString2 = s3.substr(1, s3.size());
        return isInterleave(s1, subString1, subString2);
    }
    else if ((s1[0] == s3[0]) && (s2[0] != s3[0])){
        subString1 = s1.substr(1, s1.size());
        subString2 = s3.substr(1, s3.size());
        return isInterleave(subString1, s2, subString2);
    }
    else{
        if (isInterleave(s1, s2.substr(1, s2.size()), s3.substr(1, s3.size())))
            return true;
        else if (isInterleave(s1.substr(1, s1.size()), s2, s3.substr(1, s3.size())))
            return true;
        else
            return false;
    }
//        return (isInterleave(s1, s2.substr(1, s2.size()), s3.substr(1, s3.size()))) || isInterleave(s1.substr(1, s2.size()), s2, s3.substr(1, s3.size()));
}

#endif //LEETCODE_2021_3_3_1_H
