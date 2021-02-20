//
//  88 合并两个有序数组.cpp
//  Algorithm
//
//  Created by zack on 2021/2/13.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = m-1;
        int index2 = n-1;
        int currentIndex = m + n -1;
        while(index2 >= 0) {
            if(index1 >= 0 && nums1[index1] > nums2[index2]) {
                nums1[currentIndex] = nums1[index1];
                currentIndex--;
                index1--;
            } else {
                nums1[currentIndex] = nums2[index2];
                currentIndex--;
                index2--;
            }
        }
    }
};
