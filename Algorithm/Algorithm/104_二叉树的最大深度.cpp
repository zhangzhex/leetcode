
//
//  104_二叉树的最大深度.cpp
//  Algorithm
//
//  Created by zack on 2020/7/19.
//  Copyright © 2020 zack. All rights reserved.
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        return max(leftDepth, rightDepth) + 1;
    }
};
