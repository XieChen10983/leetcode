//
// Created by Laser303 on 2021/3/1.
//

#ifndef LEETCODE_2021_3_1_3_H
#define LEETCODE_2021_3_1_3_H
#include <vector>
using namespace std;

//void dfs(int current_X, int current_Y, int m, int n, int& ans){
//    if ((current_X == n) && (current_Y == m)){
//        ans++;
//        return;
//    }
//    if (current_Y == m){
//        current_X++;
//        dfs(current_X, current_Y, m, n, ans);
//    }
//    else if (current_X == n){
//        current_Y++;
//        dfs(current_X, current_Y, m, n, ans);
//    }
//    else{
//        current_X++;
//        dfs(current_X, current_Y, m, n, ans);
//        current_X--;
//        current_Y++;
//        dfs(current_X, current_Y, m, n, ans);
//    }
//}
//
//int uniquePaths(int m, int n){
//    int current_Y = 1, current_X = 1;
//    int ans = 0;
//    dfs(current_X, current_Y, m, n, ans);
//    return ans;
//}

int uniquePaths(int m, int n){
    vector<vector<int>> v(m, vector<int>(n));
    for (int i = 0; i < n; i++)
        v[0][i] = 1;
    for (int j = 0; j < m; j++)
        v[j][0] = 1;
    for (int j = 1; j < m; j++){
        for (int i = 1; i < n; i++){
            v[j][i] = v[j - 1][i] + v[j][i - 1];
        }
    }
    return v[m - 1][n - 1];
}

#endif //LEETCODE_2021_3_1_3_H
