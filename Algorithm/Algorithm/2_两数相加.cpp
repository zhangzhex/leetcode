//
//  2_两数相加.cpp
//  Algorithm
//
//  Created by zack on 2020/5/13.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //思路：1.创建dummyHead虚拟头结点作为返回值用到，创建lasth指向新链表的最后一个元素
    //2.循环遍历l1、l2链表，同时记录进位值
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l2;
        
        ListNode *dummyHead = new ListNode(0);
        ListNode *last = dummyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int v1 = 0;
            int v2 = 0;
            if (l1 != NULL) {
                v1 = l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                v2 = l2->val;
                l2 = l2->next;
            }
            int sum = (v1 + v2 + carry)%10;
            carry = (v1 + v2 + carry)/10;
            last->next = new ListNode(sum);
            last = last->next;
        }
        if (carry > 0) {
            last->next = new ListNode(carry);
        }
        return dummyHead->next;
    }
};
