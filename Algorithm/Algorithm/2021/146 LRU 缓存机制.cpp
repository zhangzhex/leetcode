//
//  146 LRU 缓存机制.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2021/3/26.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <map>

using namespace std;

class Node {
public:
    int key;
    int value;
    Node *pre;
    Node *next;
    
    Node(int k, int v) {
        key = k;
        value = v;
    }
};

class LRUCache {
    int _capacity;
    map<int, Node*> _dic;
    Node *first;
    Node *last;
    
    void removeNode(Node *node) {
        Node *pre = node->pre;
        node->next->pre = pre;
        pre->next = node->next;
    }
    
    void insertToFirst(Node *node) {
        Node *nextNode = first->next;
        nextNode->pre = node;
        node->next = nextNode;
        first->next = node;
    }
    
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        _dic = map<int, Node*>();
        first = new Node(0, 0);
        last = new Node(0, 0);
        first->next = last;
        last->pre = first;
    }
    
    int get(int key) {
        // 不存在
        map<int , Node * > ::iterator iter = _dic.find(key);
        if(iter == _dic.end()) {
            return -1;
        }
        
        // 存在
        Node *node = _dic[key];
        removeNode(node);
        insertToFirst(node);
        return node->value;
    }
    
    void put(int key, int value) {
        // 不存在
        map<int , Node * > ::iterator iter = _dic.find(key);
        if(iter == _dic.end()) {
            // 有必要的话 先移除最后一个
            if (_dic.size() == _capacity) {
                Node *lastNode = last->pre;
                removeNode(lastNode);
                _dic.erase(lastNode->key);
            }
            Node *node = new Node(key, value);
            _dic[key] = node;
            insertToFirst(node);
        } else {// 存在
            Node *node = _dic[key];
            node->value = value;
            removeNode(node);
            insertToFirst(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
