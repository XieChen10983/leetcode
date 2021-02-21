//
// Created by Administrator on 2021/2/21.
//

#ifndef LEETCODE_2021_2_21_1_H
#define LEETCODE_2021_2_21_1_H
#include <vector>
using namespace std;
/*
 *     *   **    ***   ****    *****
 *         **    ***   ****    *****
 *               ***   ****    *****
 *                     ****    *****
 *                             *****
 */

void printMatrix(const vector<vector<int>>& m){
    for (const auto& v : m){
        for (const auto& ele : v){
            cout << ele << '\t';
        }
        cout << endl;
    }
}

int fillRound(vector<vector<int>>& matrix, int roundNum, int beginFillNum = 1){
    int size = matrix.size();
    int fillSize = size - 2 * (roundNum - 1);
    int rowBeginIndex = roundNum - 1, rowEndIndex = rowBeginIndex + fillSize;
    for (int i = rowBeginIndex; i < rowEndIndex; i++){   //上横
        matrix[rowBeginIndex][i] = beginFillNum;
//        cout << "----row" << rowBeginIndex << " col" << i << "----" << endl;
//        printMatrix(matrix);
        beginFillNum++;
    }
    for (int j = rowBeginIndex + 1; j < rowEndIndex; j++){  // 右竖
        matrix[j][rowEndIndex-1] = beginFillNum;
//        cout << "----row" << j << " col" << rowEndIndex - 1 << "----" << endl;
//        printMatrix(matrix);
        beginFillNum++;
    }
    for (int i = rowEndIndex - 2; i >= rowBeginIndex; i--){
        matrix[rowEndIndex - 1][i] = beginFillNum;
//        cout << "----row" << rowEndIndex - 1 << " col" << i << "----" << endl;
//        printMatrix(matrix);
        beginFillNum++;
    }
    for (int j = rowEndIndex - 2; j >= rowBeginIndex+1; j--){
        matrix[j][rowBeginIndex] = beginFillNum;
//        cout << "----row" << rowBeginIndex << " col" << j << "----" << endl;
//        printMatrix(matrix);
        beginFillNum++;
    }
    return beginFillNum;
}

vector<vector<int>> generateMatrix(int n) {

    vector<vector<int>> matrix;
    matrix.reserve(n);
    for (int i = 0; i < n; i++)
            matrix.emplace_back(n);
    int fillTime = (n + 1) / 2;
    int beginNum = 1;
    for (int roundNum = 1; roundNum <= fillTime; roundNum++){
        beginNum = fillRound(matrix, roundNum, beginNum);
    }
    return matrix;
}

#endif //LEETCODE_2021_2_21_1_H
