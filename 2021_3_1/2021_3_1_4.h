//
// Created by Laser303 on 2021/3/1.
//

#ifndef LEETCODE_2021_3_1_4_H
#define LEETCODE_2021_3_1_4_H
#include <vector>
using namespace std;

void printVV(const vector<vector<int>>& vv){
    for (const auto& v : vv){
        for (const auto& ele : v){
            cout << ele << '\t';
        }
        cout << endl;
    }
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
    int m = (int)obstacleGrid.size(), n = (int)obstacleGrid[0].size();
    int left = 0, up = 1;
    while ((left < n) && (obstacleGrid[0][left] == 0)){
        obstacleGrid[0][left] = 1;
        left++;
    }
    while (left < n){
        obstacleGrid[0][left] = 0;
        left++;
    }
    while ((up < m) && (obstacleGrid[up][0] == 0)){
        obstacleGrid[up][0] = 1;
        up++;
    }
    while (up < m){
        obstacleGrid[up][0] = 0;
        up++;
    }
    for (int j = 1; j < m; j++){
        for (int i = 1; i < n; i++){
            if (obstacleGrid[j][i] == 1)
                obstacleGrid[j][i] = 0;
            else
                obstacleGrid[j][i] = obstacleGrid[j - 1][i] + obstacleGrid[j][i - 1];
        }
    }
    return obstacleGrid[m - 1][n - 1];
}

#endif //LEETCODE_2021_3_1_4_H
