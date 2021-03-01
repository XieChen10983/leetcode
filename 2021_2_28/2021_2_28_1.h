//
// Created by Laser303 on 2021/2/28.
//

#ifndef LEETCODE_2021_2_28_1_H
#define LEETCODE_2021_2_28_1_H
#include <vector>
#include <string>
using namespace std;

//bool used(const vector<string>& board, int row, int col, int n){
//    for (int i = 0; i < n; i++){
//        if (board[i][col] == 'Q'){
//            return true;
//        }
//    }
//    for (int i = 0; i < n; i++){
//        if (board[row][i] == 'Q'){
//            return true;
//        }
//    }
//
//}

void initialize(vector<string>& board, int row, int col, int n){
    board.clear();
    string s(n, ' ');
    for (int i = 0; i < n; i++)
        board.emplace_back(s);
    // 初始化棋盘的第row行
    for (int j = 0; j < n; j++){
        if (j == col)
            board[row][j] = 'Q';
        else
            board[row][j] = '.';
    }

    // 初始化棋盘的列
    for (int j = row + 1; j < n; j++)
        board[j][col] = '.';

    // 初始化棋盘的对角线方向
    for (int j = 0; j < n; j++){
        if (j == row || (j + col - row < 0) || (j + col - row >= n))
            continue;
        else
            board[j][j + col - row] = '.';
    }

    // 初始化棋盘的逆对角线方向
    for (int j = 0; j < n; j++)
        if (j == row || (row + col - j < 0) || (row + col - j >= n))
            continue;
        else
            board[j][row + col - j] = '.';
}

vector<vector<string>> solveQueens(int n){
    vector<vector<string>> ans;
    for (int first = 0; first < n; ){
        loop: first++;
        vector<string> board;
        initialize(board, 0, first, n);
        for (const auto& ele : board)
            cout << ele << endl;

        int i = 1;
        for (int row = 1; row < n; row++){
            for (int col = 0; col < n; col++){
                if ()
            }
        }
    }
    return ans;
}

#endif //LEETCODE_2021_2_28_1_H
