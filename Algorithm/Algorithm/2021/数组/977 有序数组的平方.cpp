//
//  977 有序数组的平方.cpp
//  Algorithm
//
//  Created by zack on 2021/2/14.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    // 变成合并两个有序数组问题
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> nums1;
        vector<int> nums2;
        for (int i = 0 ; i < nums.size(); i++) {
            int value = nums[i];
            if (value < 0) {
                nums2.insert(nums2.begin(), value*value);
            }else {
                nums1.push_back(value*value);
            }
        }
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        for (int i = 0; i < nums2.size(); i++) {
            nums1.push_back(-1);
        }
        
        merge(nums1, m, nums2, n);
        return nums1;
    }
    
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
