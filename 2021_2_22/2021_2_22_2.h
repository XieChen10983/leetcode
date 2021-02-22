//
// Created by Laser303 on 2021/2/22.
//

#ifndef LEETCODE_2021_2_22_2_H
#define LEETCODE_2021_2_22_2_H
#include <string>
#include <vector>
using namespace std;

void removeSpace(string& s){
    int index = 0;
    while (index < s.size()){
        if (s[index] == ' ')
            index++;
        else
            break;
    }
    s = s.substr(index, s.size());
    index = (int)s.size() - 1;
    while (index >= 0){
        if (s[index] == ' ')
            index--;
        else{
            s = s.substr(0, index + 1);
            break;
//            return s;
        }
    }
}

string reverseWords(string s){
    removeSpace(s);
    if (s.empty())
        return "";
    string word;
    vector<string> words;
    int currentIndex = 0;
    while (currentIndex < s.size()){
        while ((currentIndex < s.size()) && (s[currentIndex] != ' ')){
            word += s[currentIndex];
            currentIndex++;
        }
        words.push_back(word);
        word = "";
        while ((currentIndex < s.size()) && (s[currentIndex] == ' '))
            currentIndex++;
    }
    string ans;
    for (int i = (int)words.size() - 1; i >= 0; i--){
        ans += words[i];
        ans += ' ';
    }
    return ans.substr(0, ans.size() - 1);
}

#endif //LEETCODE_2021_2_22_2_H
