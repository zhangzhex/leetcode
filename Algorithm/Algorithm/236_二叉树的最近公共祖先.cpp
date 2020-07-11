//
//  236_二叉树的最近公共祖先.cpp
//  Algorithm
//
//  Created by zack on 2020/7/11.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    /**
     *思路: 类似与后续递归，
     *终止条件之一：root == null || p == root || q == root
     *
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // 公共祖先是根节点的情况
        if (root == NULL || p == root || q == root) {
            return root;
        }
        
        // 左子树找
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        // 右子树找
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        //左右子树都能找到，返回根节点
        if (left != NULL && right != NULL) {
            return root;
        }
        
        //否则返回左子树或右子树
        return (left != NULL) ? left : right;
    }
};

