//
//  剑指 Offer 55 - II 平衡二叉树.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2021/4/11.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        if (isBalanced(root->left) && isBalanced(root->right) && abs(treeHeight(root->left) - treeHeight(root->right)) <= 1) {
            return true;
        } else {
            return false;
        }
    }
    int treeHeight(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        return max(treeHeight(node->left), treeHeight(node->right)) + 1;
    }
};
