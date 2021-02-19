//
// Created by Laser303 on 2021/2/17.
//

#ifndef LEETCODE_2021_2_17_4_H
#define LEETCODE_2021_2_17_4_H
#include <vector>
#include <string>
using namespace std;

bool isValid(const string& s){

    int balance = 0;
    for (const auto& ele : s){
        if (ele == '(')
            balance++;
        else
            balance--;
        if (balance < 0)
            return false;
    }
    return balance == 0;
}

void generate(string s, int pos, vector<string>& v){
    if (pos == s.length() - 1){
        s[pos] = '(';
        if (isValid(s))
            v.push_back(s);
        s[pos] = ')';
        if (isValid(s))
            v.push_back(s);
    }
    else{
        s[pos] = '(';
        generate(s, pos + 1, v);
        s[pos] = ')';
        generate(s, pos + 1, v);
    }
}

void backTrack(vector<string>& ans, string cur, int open, int close, int n){
    if (cur.size() == n * 2){
        ans.push_back(cur);
        return;
    }

    if (open < n){
        cur.push_back('(');
        backTrack(ans, cur, open + 1, close, n);
        cur.pop_back();
    }

    if (close < open){
        cur.push_back(')');
        backTrack(ans, cur, open, close + 1, n);
//        cur.pop_back();
    }
}

vector<string> generateParenthesis(int n){
    vector<string> result;
    string current;
    backTrack(result, current, 0, 0, n);
    return result;
}

#endif //LEETCODE_2021_2_17_4_H
