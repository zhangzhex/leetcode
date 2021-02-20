//
//  234 回文链表.cpp
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        if (head->next->next == nullptr) return head->val==head->next->val;
            
        //找到中间节点
        ListNode *middleNode = middleList(head);
        // 翻转链表
        ListNode *rhead = reverseList(middleNode->next);
        
        while (rhead != nullptr) {
            if (rhead->val != head->val) return false;
            head = head->next;
            rhead = rhead->next;
        }
        
        return true;
    }
    
    ListNode* middleList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = nullptr;
        while (head != nullptr) {
            ListNode *temp = head->next;
            head->next = newHead;
            newHead = head;
            head = temp;
        }
        return newHead;
    }
};
