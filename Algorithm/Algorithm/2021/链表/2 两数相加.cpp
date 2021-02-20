//
//  2 两数相加.cpp
//  Algorithm
//
//  Created by zack on 2021/2/14.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *tail = dummyHead;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int v1 = 0;
            if (l1 != nullptr) {
                v1 = l1->val;
                l1 = l1->next;
            }
            
            int v2 = 0;
            if (l2 != nullptr) {
                v2 = l2->val;
                l2 = l2->next;
            }
            
            int sum = v1 + v2 + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return dummyHead->next;
    }
};
