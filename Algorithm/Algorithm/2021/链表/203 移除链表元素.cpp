//
//  203 移除链表元素.cpp
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *newHead = new ListNode();
        ListNode *newTail = newHead;
        while (head != nullptr) {
            if (head->val != val) {
                newTail->next = head;
                newTail = head;
            }
            head = head->next;
        }
        newTail->next = nullptr;
        return newHead->next;
    }
};
