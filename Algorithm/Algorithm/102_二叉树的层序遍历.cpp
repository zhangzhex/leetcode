

//
//  102_二叉树的层序遍历.cpp
//  Algorithm
//
//  Created by zack on 2020/7/19.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> nodes;
        if (root == NULL) return nodes;

        // 第一个元素
        vector<int> rv;
        rv.push_back(root->val);
        nodes.push_back(rv);
        
        queue<vector<TreeNode *>> q;
        vector<TreeNode *>rn;
        rn.push_back(root);
        q.push(rn);
        
        while (!q.empty()) {
            vector<TreeNode *> nodeVec = q.front();
            q.pop();
            
            vector<TreeNode *> ln;
            vector<int> lv;
            for (int i = 0; i < nodeVec.size(); i++) {
                TreeNode *node = nodeVec[i];
                if (node->left != NULL) {
                    lv.push_back(node->left->val);
                    ln.push_back(node->left);
                }
                
                if (node->right != NULL) {
                    lv.push_back(node->right->val);
                    ln.push_back(node->right);
                }
            }
            if (lv.size() > 0) nodes.push_back(lv);
            if (ln.size() > 0) q.push(ln);
        }
        
        return nodes;
    }
};
