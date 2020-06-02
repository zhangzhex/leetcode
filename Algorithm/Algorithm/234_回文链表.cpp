//
//  234_回文链表.cpp
//  Algorithm
//
//  Created by zack on 2020/5/19.
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
    /**
     *思路：1.快慢指针找中心节点
     *2.翻转中心节点右侧链表，返回翻转后的链表头节点
     *3.左右链表遍历对比
     */
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }
        if (head->next == NULL) {
            return true;
        }
        if (head->next->next == NULL) {
            return head->val == head->next->val;
        }
        
        ListNode *middle = middleList(head);
        ListNode *rHead = reverseList(middle->next);
        
        while (rHead != NULL) {
            if (head->val != rHead->val) {
                return false;
            }
            head = head->next;
            rHead = rHead->next;
        }
        return true;
    }
    
    
    // 找中间节点
    ListNode *middleList(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    // 翻转链表
    ListNode *reverseList(ListNode *head) {
        ListNode *newHead = NULL;
        while (head != NULL) {
            ListNode *temp = head->next;
            head->next = newHead;
            newHead = head;
            head = temp;
        }
        return newHead;
    }
};
