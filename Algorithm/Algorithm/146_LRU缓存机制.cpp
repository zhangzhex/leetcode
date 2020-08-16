//
//  146_LRU缓存机制.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2020/8/17.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <map>
using namespace std;

class Node{
public:
    Node *pre;
    Node *next;
    int value;
    int key;
    Node(int k, int v) {
        value = v;
        key = k;
    }
};

class LRUCache {
    map<int, Node*> _map;
    int _capacity;
    Node *first;
    Node *last;
    
    void removeNode(Node *node) {
        Node *p = node->pre;
        p->next = node->next;
        node->next->pre = p;
    }
    
    void insertNodeToFirst(Node *node) {
        first->next->pre = node;
        node->next = first->next;
        node->pre = first;
        first->next = node;
    }
    
public:
    LRUCache(int capacity) {
        _map = map<int, Node*>();
        _capacity = capacity;
        first = new Node(0, 0);
        last = new Node(0, 0);
        first->next = last;
        last->pre = first;
    }
    
    int get(int key) {
        map<int, Node*>::iterator iter = _map.find(key);
        if(iter == _map.end()) {
            return -1;
        }
        Node *node = _map[key];
        removeNode(node);
        insertNodeToFirst(node);
        
        return node->value;
    }
    
    void put(int key, int value) {
        Node *node = NULL;
        map<int, Node*>::iterator iter = _map.find(key);
        if(iter == _map.end()) {
            node = new Node(key, value);
            if (_map.size() == _capacity) {
                _map.erase(last->pre->key);
               removeNode(last->pre);
            }
            insertNodeToFirst(node);
            _map[key] = node;
        } else {
            node = _map[key];
            node->value = value;
            removeNode(node);
            insertNodeToFirst(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
