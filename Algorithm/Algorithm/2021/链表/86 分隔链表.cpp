//
//  86 分隔链表.cpp
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return nullptr;
        
        ListNode *lHead = new ListNode(0);
        ListNode *lTail = lHead;
        ListNode *rHead = new ListNode(0);
        ListNode *rTail = rHead;
        
        while (head != nullptr) {
            if (head->val < x) {
                lTail->next = head;
                lTail = head;
            } else {
                rTail->next = head;
                rTail = head;
            }
            head = head->next;
        }
        rTail->next = nullptr;
        lTail->next = rHead->next;
        
        return lHead->next;
    }
};
