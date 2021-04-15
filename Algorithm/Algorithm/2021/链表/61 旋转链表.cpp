//
//  61 旋转链表.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2021/4/15.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;
        
        ListNode *curr = head;
        ListNode *tail = nullptr;
        int count = 0;
        while (curr) {
            count++;
            // 尾结点
            if (curr->next == nullptr) {
                tail = curr;
            }
            curr = curr->next;
        }
        
        int offset = k % count;
        if (offset == 0) {
            return head;
        }
        
        // 找新的head
        curr = head;
        for (int i = 0 ; i < count - offset - 1; i++) {
            curr = curr->next;
        }
        ListNode *newHead = curr->next;
        curr->next = nullptr;
        
        // 头尾相连
        tail->next = head;
        
        return newHead;
    }
};
