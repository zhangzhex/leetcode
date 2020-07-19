

//
//  98_验证二叉搜索树.cpp
//  Algorithm
//
//  Created by zack on 2020/7/18.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> nodes;
    bool isValidBST(TreeNode* root) {
        inorderTraversel(root);
        
        int pre = 0;
        for (int i = 0; i < nodes.size() ; i++) {
            if (i == 0) {
                pre = nodes[i];
            } else {
                if (nodes[i] <= pre) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void inorderTraversel(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorderTraversel(root->left);
        nodes.push_back(root->val);
        inorderTraversel(root->right);
    }
};
