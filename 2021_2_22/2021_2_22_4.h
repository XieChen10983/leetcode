//
// Created by Laser303 on 2021/2/22.
//

#ifndef LEETCODE_2021_2_22_4_H
#define LEETCODE_2021_2_22_4_H
#include <string>
#include <vector>
using namespace std;

string simplifyPath(string path){
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
            if (dir != ".")
                dirs.push_back(dir);
        }
    }
    // "/home/foo/.ssh/../.ssh2/authorized_keys/"
    string ans = "/";
    for (const auto& dir_ : dirs){
        if (dir_ == ".."){
            if (ans == "/")
                continue;
            else{
                ans.pop_back();
                unsigned int t = ans.size() - 1;
                for (; t >= 0; t--){
                    if (ans[t] != '/')
                        continue;
                    else
                        break;
                }
                ans = ans.substr(0, t + 1);
                if (ans.empty())
                    ans = "/";
            }
        }
        else{
            ans += dir_ + "/";
        }
    }
    if (ans.back() == '/'){
        if (ans.size() != 1)
            ans.pop_back();
    }
    return ans;
}

#endif //LEETCODE_2021_2_22_4_H
