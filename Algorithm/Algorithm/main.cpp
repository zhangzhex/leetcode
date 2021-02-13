//
//  main.cpp
//  Algorithm
//
//  Created by zack on 2020/4/11.
//  Copyright © 2020 zack. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

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



int main(int argc, const char * argv[]) {
    // insert code here...

    LRUCache* obj = new LRUCache(2);
    obj->put(2, 1);
    obj->put(2, 2);
    int param_1 = obj->get(2);
    cout <<"value1="<< param_1 << endl;
    obj->put(1,1);
    obj->put(4,1);
    int param_2 = obj->get(2);
    cout <<"value2="<< param_2 << endl;
    
    
//    ["LRUCache","put","put","get","put","put","get"]
//    [[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]
//    map<int, int *> _map = map<int, int *>();
//    _map[10] = 20;
//    if (_map[20] == NULL) {
//            cout <<"value="<< _map[20] << endl;
//    }
    
    return 0;
}
