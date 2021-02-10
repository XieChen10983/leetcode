//
// Created by Administrator on 2021/2/10.
//

#ifndef LEETCODE_2021_2_10_1_H
#define LEETCODE_2021_2_10_1_H
#include <string>
#include <map>
#include <utility>
//#include <algorithm>
using namespace std;

bool sameMap(map<char, int>& m1, map<char, int>& m2){
    if(m1.size() != m2.size())
        return false;
    for (const auto& ele : m2){
        cout << "checking " << ele.first << endl;
        if (m1.find(ele.first) == m1.end())
            return false;
        else if (m1[ele.first] != ele.second)
            return false;
        else
            ;
    }
    return true;
}

bool checkInclusion(string& s1, string& s2){
    if (s1.empty())
        return true;
    if (s2.size() < s1.size())
        return false;
    map<char, int> m;
    for (const auto& c : s1){
        m[c]++;
    }
    map<char, int> m2;
    int currentIndex = 0;
    for (int i = currentIndex; i < s1.size(); i++){
        m2[s2[i]]++;
    }
    if (sameMap(m, m2))
        return true;
    while(currentIndex < s2.size() - s1.size()){
        currentIndex++;

        if (m2[s2[currentIndex - 1]] == 1){
            m2.erase(s2[currentIndex - 1]);
        }
        else
            m2[s2[currentIndex - 1]]--;
        char c = s2[currentIndex + s1.size() - 1];
        m2[c]++;
        if (sameMap(m, m2)){
            return true;
        }
        else
            ;
    }
    return false;
}

#endif //LEETCODE_2021_2_10_1_H
