//
//  160_相交链表.cpp
//  Algorithm
//
//  Created by zack on 2020/5/14.
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
    /*
     *思路：利用两条链表分别互相拼接达到等长效果，遍历链表(如果相交，最终会同时指向同一节点：即目标节点)
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        ListNode *currA = headA;
        ListNode *currB = headB;
        while (currA != currB) {
            currA = currA == NULL ? headB : currA->next;
            currB = currA == NULL ? headA : currB->next;
        }
        return currA;
    }
};
