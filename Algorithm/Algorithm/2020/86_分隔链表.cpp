//
//  86_分隔链表.cpp
//  Algorithm
//
//  Created by zack on 2020/5/18.
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
    /* 要求：时间复杂度O(n),空间复杂度O(1)
     * 思路：创建两个左右链表的思想，遍历链表过程，把每个节点串连到左或者右链表，最后左链表尾部连上右链表头部
     */
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return NULL;
        
        ListNode *lHead = new ListNode(0);
        ListNode *lTail = lHead;
        ListNode *rHead = new ListNode(0);
        ListNode *rTail = rHead;
        
        while (head != NULL) {
            
            if (head->val < x) {
                lTail->next = head;
                lTail = head;
            } else {
                rTail->next = head;
                rTail = head;
            }
            
            head = head->next;
        }
        
        // 存在右链表尾部非NULL情况
        rTail->next = NULL;
        lTail->next = rHead->next;
        return lHead->next;
    }
};
