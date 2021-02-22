//
// Created by Laser303 on 2021/2/22.
//

#ifndef LEETCODE_2021_2_22_1_H
#define LEETCODE_2021_2_22_1_H
#include <string>
using namespace std;

int compare(string compare1, string compare2){
    if (compare1.size() < compare2.size())
        return -1;
    else if (compare2.size() < compare1.size())
        return 1;
    else{
        for (int i = 0; i < compare1.size(); i++){
            if (compare1[i] > compare2[i])
                return 1;
            else if (compare1[i] < compare2[i])
                return -1;
            else
                continue;
        }
        return 0;
    }
}

int getCompareNum(string version, string& compare, int index){
    compare = "";
    while (index < version.size()){
        while ((index < version.size()) && (version[index] == '0'))
            index++;
        if (index == version.size()){
            compare = "0";
            return index;
        }
        else{
            for (int i = index; i < version.size(); i++){
                if (version[i] != '.')
                    compare += version[i];
                else{
                    if (compare.empty())
                        compare = "0";
                    return i + 1;
                }
            }
            return version.size();
        }
    }
    compare = "0";
    return index;
}

int compareVersion(string version1, string version2) {
    string compare1, compare2;
    int index1 = 0, index2 = 0;
    while ((index1 < version1.size()) || (index2 < version2.size())){
        index1 = getCompareNum(version1, compare1, index1);
        index2 = getCompareNum(version2, compare2, index2);
        if (compare(compare1, compare2) != 0)
            return compare(compare1, compare2);
//        cout << "-----------------------------" << endl;
//        cout << compare1 << "     " << compare2 << endl;
    }
//    return compare(compare1, compare2);
    return 0;
}

#endif //LEETCODE_2021_2_22_1_H
