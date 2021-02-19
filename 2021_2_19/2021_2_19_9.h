//
// Created by Laser303 on 2021/2/19.
//

#ifndef LEETCODE_2021_2_19_9_H
#define LEETCODE_2021_2_19_9_H
#include <stack>
//#include <utility>
using namespace std;

class MinStack{
public:
    stack<pair<int, int>> v;
    int min_ ;
    MinStack(){min_ = INT_MAX;};

    void push(int x){
        if (x < min_)
            min_ = x;
        v.push({x, min_});
    }

    void pop(){
        v.pop();
        if (!v.empty())
            min_ = v.top().second;
        else
            min_ = INT_MAX;
    }

    int top(){
        return v.top().first;
    }

    int getMin() const{
        return min_;
    }
};
#endif //LEETCODE_2021_2_19_9_H
