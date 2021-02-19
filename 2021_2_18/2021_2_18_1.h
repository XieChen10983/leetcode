//
// Created by Laser303 on 2021/2/18.
//

#ifndef LEETCODE_2021_2_18_1_H
#define LEETCODE_2021_2_18_1_H
#include <stack>
using namespace std;
int divide(int dividend, int divisor){
    if (dividend == 0)
        return 0;
    if (divisor == 1)
        return dividend;
    if (dividend == -2147483648){
        if (divisor == -1)
            return 2147483647;
        else
            if (divisor < 0){
                dividend -= divisor;
                return divide(dividend, divisor) + 1;
            }
            else{
                dividend += divisor;
                return divide(dividend, divisor) - 1;
            }
    }
    if (divisor == -1)
        return -dividend;

    /////////////////////////////////////////////////////////////////
    int dividend_abs = dividend > 0 ? dividend : -dividend;
    int divisor_abs = divisor > 0 ? divisor : -divisor;
//    int ans = 0;

    if (divisor_abs > dividend_abs)
        return 0;
    stack<int> stk;
    stack<int> stk1;
    int beishu = 1;
    while (dividend_abs >= divisor_abs){
        stk.push(divisor_abs);
        stk1.push(beishu);
//        divisor_abs = divisor_abs < 1073741824 ? divisor_abs + divisor_abs : INT_MAX;
        if (divisor_abs < 1073741824)
            divisor_abs += divisor_abs;
        else
            break;
//        beishu = beishu < 1076741824 ? beishu + beishu : INT_MAX;
        if (beishu < 1073741824)
            beishu += beishu;
        else
            break;
    }
    int ans = 0;
    while (!stk.empty()){
        if (dividend_abs >= stk.top()){
            ans += stk1.top();
            stk1.pop();

            dividend_abs -= stk.top();
            stk.pop();
        }
        else{
            stk.pop();
            stk1.pop();
        }
    }

    if (((dividend > 0) && (divisor > 0)) || ((dividend < 0) && (divisor < 0))){
        return ans;
    }
    else
        return -ans;

//    //////////////////////////////////////////////////////////////////
//    while ((dividend_abs > divisor_abs)){
//        dividend_abs -= divisor_abs;
//        ans++;
//    }
//    if (((dividend > 0) && (divisor > 0)) || ((dividend < 0) && (divisor < 0))){
//        return ans;
//    }
//    else
//        return -ans;
}

#endif //LEETCODE_2021_2_18_1_H
