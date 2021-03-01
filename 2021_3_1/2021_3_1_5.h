//
// Created by Laser303 on 2021/3/1.
//

#ifndef LEETCODE_2021_3_1_5_H
#define LEETCODE_2021_3_1_5_H
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid){
    int m = (int)grid.size(), n = (int)grid[0].size();
    for (int i = 1; i < n; i++)
        grid[0][i] += grid[0][i - 1];
    for (int j = 1; j < m; j++)
        grid[j][0] += grid[j - 1][0];
    for (int j = 1; j < m; j++){
        for (int i = 1; i < n; i++){
            grid[j][i] += min(grid[j - 1][i], grid[j][i - 1]);
        }
    }
    return grid[m - 1][n - 1];
}

#endif //LEETCODE_2021_3_1_5_H
