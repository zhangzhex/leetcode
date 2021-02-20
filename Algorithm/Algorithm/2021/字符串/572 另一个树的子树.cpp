//
//  572 另一个树的子树.cpp
//  Algorithm
//
//  Created by zack on 2021/2/18.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <string>

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string str;
        serializeTree(s, str);
        
        string str2;
        serializeTree(t, str2);
        
        string::size_type idx = str.find(str2);
        if (idx == string::npos) return false;
        return true;
    }
    
    void serializeTree(TreeNode* root, string &s) {
        if (root->left == nullptr) {
            s.append("#!");
        }else {
            serializeTree(root->left, s);
        }
        if (root->right == nullptr) {
            s.append("#!");
        }else {
            serializeTree(root->right, s);
        }
        s = s + to_string(root->val) + "!";
    }
};
