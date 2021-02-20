//
//  203_移除链表元素.cpp
//  Algorithm
//
//  Created by zack on 2020/5/11.
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
    //思路：1、创建头、尾指针，共同指向虚拟头结点
    // 2、遍历链表，以构造新链表的形式移动尾指针
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return head;
        
        ListNode *newHeader = new ListNode(0);
        ListNode *newTail = newHeader;
        while (head != NULL) {
            if (head->val != val) {
                newTail->next = head;
                newTail = head;
            }
            head = head->next;
        }
        newTail->next = NULL;
        return newHeader->next;
    }
};
