//
// Created by Administrator on 2021/2/21.
//

#ifndef LEETCODE_2021_2_21_2_H
#define LEETCODE_2021_2_21_2_H
#include <vector>
using namespace std;

void printMatrix(const vector<vector<int>>& m){
    for (const auto& v : m){
        for (const auto& ele : v){
            cout << ele << '\t';
        }
        cout << endl;
    }
}

vector<vector<int>> generateMatrix(int m, int n) {
    int target = m * n;
    int currentNum = 1;

    vector<vector<int>> matrix;
    matrix.reserve(m);
    for (int i = 0; i < m; i++)
        matrix.emplace_back(n);
    int l = 0, r = n - 1, t = 0, b = m - 1;
    while (currentNum <= target){
        for (int i = l; i <= r; i++){
            matrix[t][i] = currentNum++;
            if (currentNum > target)
                return matrix;
        }
        t++;

        for (int j = t; j <= b; j++){
            matrix[j][r] = currentNum++;
            if (currentNum > target)
                return matrix;
        }
        r--;

        for (int i = r; i >= l; i--){
            matrix[b][i] = currentNum++;
            if (currentNum > target)
                return matrix;
        }
        b--;

        for (int j = b; j >= t; j--){
            matrix[j][l] = currentNum++;
            if (currentNum > target)
                return matrix;
        }
        l++;
    }
    return matrix;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int rows = matrix.size();
    if (matrix.empty())
        return ans;
    int cols = matrix[0].size();
    if (cols == 0)
        return ans;
    int target = rows * cols;
    int currentNum = 1;
    int l = 0, r = cols - 1, t = 0, b = rows - 1;
    while (currentNum <= target){
        for (int i = l; i <= r; i++){
            ans.push_back(matrix[t][i]);
            currentNum++;
            if (currentNum > target)
                return ans;
        }
        t++;

        for (int j = t; j <= b; j++){
            ans.push_back(matrix[j][r]);
            currentNum++;
            if (currentNum > target)
                return ans;
        }
        r--;

        for (int i = r; i >= l; i--){
            ans.push_back(matrix[b][i]);
            currentNum++;
            if (currentNum > target)
                return ans;
        }
        b--;

        for (int j = b; j >= t; j--){
            ans.push_back(matrix[j][l]);
            currentNum++;
            if (currentNum > target)
                return ans;
        }
        l++;
    }
    return ans;
}

#endif //LEETCODE_2021_2_21_2_H
