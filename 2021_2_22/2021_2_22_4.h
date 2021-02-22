//
// Created by Administrator on 2021/2/22.
//

#ifndef LEETCODE_2021_2_22_4_H
#define LEETCODE_2021_2_22_4_H
#include <string>
#include <vector>
using namespace std;

string simplifyPath(string path) {
    string dir;
    vector<string> dirs;
    int index = 0;
    while (index < path.size()){
        dir = "";
        if (path[index] == '/'){
            index++;
            continue;
        }
        else{
            while ((path[index] != '/') && (index < path.size())){
                dir += path[index];
                index++;
            }
            dirs.push_back(dir);
        }
    }

    for (const auto& dir_ : dirs)
        cout << dir_ << endl;
    return "";
}

#endif //LEETCODE_2021_2_22_4_H
