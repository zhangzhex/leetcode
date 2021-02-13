//
//  剑指 Offer 62_圆圈中最后剩下的数字.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/8/11.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>


class Solution {
public:
    /**
     *思路：f(n, m) = (f(n-1, m) + m) % n
     */
//    int lastRemaining(int n, int m) {
//        if (n == 1) return 0;
//        return (lastRemaining(n-1, m) + m) % n;
//    }
  
    int lastRemaining(int n, int m) {
        int res = 0;
        for (int i = 2; i <=n; i++) {
            res = (res + m) % i;
        }
        return res;
    }
    
};
