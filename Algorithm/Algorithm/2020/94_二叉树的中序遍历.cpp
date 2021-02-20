//
//  94_二叉树的中序遍历.cpp
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
    stack<TreeNode *> st;
    
    vector<int> inorderTraversal(TreeNode* root) {
        // 左节点入栈
        TreeNode *p = root;
        while (p) {
            st.push(p);
            p = p->left;
        }
        
        // 节点出栈
        while (!st.empty()) {
            TreeNode *top = st.top();
            st.pop();
            nodes.push_back(top->val);// 添加栈顶
            
            // 继续左节点入栈
            p = top->right;
            while (p) {
                st.push(p);
                p = p->left;
            }
        }
        
        return nodes;
    }

};

//class Solution {
//public:
//    vector<int> nodes;
//    vector<int> inorderTraversal(TreeNode* root) {
//        inorder(root);
//        return nodes;
//    }
//
//    void inorder(TreeNode* root) {
//        if (root == NULL) return;
//
//        inorder(root->left);
//        nodes.push_back(root->val);
//        inorder(root->right);
//    }
//};
