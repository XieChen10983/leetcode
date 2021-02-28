//
// Created by Laser303 on 2021/2/24.
//

#ifndef LEETCODE_2021_2_24_3_H
#define LEETCODE_2021_2_24_3_H
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

//void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination);
//vector<string> letterCombinations(string digits) {
//    vector<string> combinations;
//    if (digits.empty()) {
//        return combinations;
//    }
//    unordered_map<char, string> phoneMap{
//            {'2', "abc"},
//            {'3', "def"},
//            {'4', "ghi"},
//            {'5', "jkl"},
//            {'6', "mno"},
//            {'7', "pqrs"},
//            {'8', "tuv"},
//            {'9', "wxyz"}
//    };
//    string combination;
//    backtrack(combinations, phoneMap, digits, 0, combination);
//    return combinations;
//}
//
//void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination) {
//    if (index == digits.length()) {
//        combinations.push_back(combination);
//    } else {
//        char digit = digits[index];
//        const string& letters = phoneMap.at(digit);
//        for (const char& letter: letters) {
//            combination.push_back(letter);
//            backtrack(combinations, phoneMap, digits, index + 1, combination);
//            combination.pop_back();
//        }
//    }
//}


void trackback(vector<string>& combinations, string& combination, int index, string& digits, unordered_map<char, string> m){
    if (index == digits.length()){
        combinations.push_back(combination);
    }else{
        char digit = digits[index];
        const string& letter = m[digit];
        for (const char& character : letter){
            combination.push_back(character);
            trackback(combinations, combination, index + 1, digits, m);
            combination.pop_back();
        }
    }
}

vector<string> letterCombinations(string digits){
    unordered_map<char, string> m;
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";

    vector<string> v;
    string combination;
    if (digits.empty())
        return v;
    trackback(v, combination, 0, digits, m);
    return v;
}

#endif //LEETCODE_2021_2_24_3_H
