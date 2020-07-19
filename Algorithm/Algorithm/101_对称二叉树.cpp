//
//  101_对称二叉树.cpp
//  Algorithm
//
//  Created by zack on 2020/7/19.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    /**
     *思路：中序遍历，镜像需要区分左右，左为正数，右为负数。中序遍历
     */
    vector<int> nodes;
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return false;
        }
        inorderTraversal(root);
        if (nodes.size() == 1) {
            return true;
        }
        int left = 0;
        int right = (int)nodes.size() - 1;
        while (left > right) {
            if (nodes[left] != nodes[right]) {
                return false;
            }
            left--;
            right--;
        }
        return true;
    }
    
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        inorderTraversal(root->left);
        
        nodes.push_back(root->val);
        
        inorderTraversal(root->right);
    }
};
