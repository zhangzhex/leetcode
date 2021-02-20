//
//  88-合并两个有序数组.cpp
//  Algorithm
//
//  Created by zack on 2020/4/11.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    //思路：双指针指向尾部， 时间复杂度O(m+n) 空间复杂度O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = m;
        int index2 = n;
        int current = m + n - 1;

        while(index2 >= 0) {
            if(index1 >= 0 && nums1[index1] > nums2[index2]) {
                nums1[current] = nums1[index1];
                current--;
                index1--;
            } else {
                nums1[current] = nums1[index2];
                current--;
                index2--;
            }
        }
    }
};
