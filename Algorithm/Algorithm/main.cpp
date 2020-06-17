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

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     *思路：利用前/中/后序i遍历二叉树生成字符串，判断包含关系。注意：空节点也需标出，得到唯一对应的树结构
     */
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL || t == NULL ) {
            return false;
        }
        string str1 = treeToString(s);
        string str2 = treeToString(t);
        
        return (str1.find(str2) != string:: npos);
    }
    
    string treeToString(TreeNode *s) {
        string str;
        _treeToString(s, str);
        return str;
    }
    
    void _treeToString(TreeNode *s, string &str) {
        
        if (s->left == NULL) {
            str = str + "#|";
        } else {
            _treeToString(s->left, str);
        }
        
        if (s->right == NULL) {
            str = str + "#|";
        } else {
            _treeToString(s->right, str);
        }
        
        str = str + to_string(s->val) + "|";
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    map<char, int> mapString;
    mapString['a'] = 1;
    
    map<char, int>::iterator iter = mapString.find('b');
    if(iter != mapString.end()) {
        cout<<"Find, the value is "<<iter->second<<endl;
    }
          
        cout << mapString['b'] << endl;
    return 0;
}
