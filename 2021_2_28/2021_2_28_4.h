//
// Created by Laser303 on 2021/2/28.
//

#ifndef LEETCODE_2021_2_28_4_H
#define LEETCODE_2021_2_28_4_H
#include <vector>
#include <set>
using namespace std;

void printVV(const vector<vector<int>>& vv){
    for (const auto& v : vv){
        for (const auto& ele : v){
            cout << ele << '\t';
        }
        cout << endl;
    }
}

void setZeroCol(vector<vector<int>>& matrix, int j){
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int row = 0; row < rows; row++)
        matrix[row][j] = 0;
}

void setZeroRow(vector<vector<int>>& matrix, int i){
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int col = 0; col < cols; col++)
        matrix[i][col] = 0;
}

void setZeroes(vector<vector<int>>& matrix){
    if (matrix.empty())
        return;
    int m = matrix.size();
    int n = matrix[0].size();
    if (n == 0)
        return;
    set<int> cols, rows;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (matrix[i][j] == 0){
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    for (int row : rows){
        setZeroRow(matrix, row);
    }
    for (int col : cols)
        setZeroCol(matrix, col);
}

#endif //LEETCODE_2021_2_28_4_H
