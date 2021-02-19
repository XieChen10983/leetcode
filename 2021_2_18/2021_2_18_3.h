//
// Created by Laser303 on 2021/2/18.
//

#ifndef LEETCODE_2021_2_18_3_H
#define LEETCODE_2021_2_18_3_H
#include <vector>
#include <string>
using namespace std;

string multiply(string num1, string num2){
    if ((num1 == "0") || (num2 == "0"))
        return "0";
    int size_1 = num1.size(), size_2 = num2.size();
//    int data[size_1 + size_2] = {0, };
    vector<int> data(size_2 + size_1);
    for (int i = size_1 - 1; i >= 0; i--){
        int x = num1.at(i) - '0';
        for (int j = size_2 - 1; j >= 0; j--){
            int y = num2.at(j) - '0';
            data[i + j + 1] += x * y;
        }
    }

    for (int i = size_1 + size_2 - 1; i > 0; i--){
        data[i - 1] += data[i] / 10;
        data[i] %= 10;
    }

    int beginIndex = data[0] == 0 ? 1 : 0;
    string ans;
    while (beginIndex < size_1 + size_2) {
        ans.push_back(data[beginIndex]);
        beginIndex++;
    }
    cout << "ans: " << ans << endl;
    for (auto &c: ans) {
        c += '0';
    }
    return ans;
}
#endif //LEETCODE_2021_2_18_3_H
