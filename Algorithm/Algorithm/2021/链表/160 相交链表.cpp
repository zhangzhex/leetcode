//
//  160 相交链表.cpp
//  Algorithm
//
//  Created by zack on 2021/2/14.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        
        ListNode *currA = headA;
        ListNode *currB = headB;
        while (currA != currB) {
            currA = currA==nullptr ? headB : currA->next;
            currB = currB==nullptr ? headA : currB->next;
        }
        return currA;
    }
};

