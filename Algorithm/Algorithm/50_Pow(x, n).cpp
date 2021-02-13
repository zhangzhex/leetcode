


//
//  50_Pow(x, n).cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/7/30.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>


class Solution {
    /**
     *思路：分治思想，时间复杂度log(n)
     * x^10 = x^5 * x^5;
     */
public:
//    double myPow(double x, int n) {
//        if (n == 0) return 1;
//        if (n == -1) return 1/x;
//
//        bool odd = n & 1;
//        double half = myPow(x, n >> 1);
//        half *=half;
//        return odd ? x * half: half;
//    }
    
    double myPow(double x, int n) {
        long y = n;
        if (n < 0) {
            y = -(long)n;
        }
        double result = 1.0;
        while (y > 0) {
            // 有效位
            if ((y & 1) == 1) {
                result *= x;
            }
            x *=x;
            y = y >> 1;
        }
        return n < 0 ? 1 / result : result;
    }
};
