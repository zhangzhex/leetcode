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
                if (nodes[i] <= pre) return false;
                pre = nodes[i];
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





int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode *root = new TreeNode(5);
    TreeNode *left = new TreeNode(1);
    TreeNode *right = new TreeNode(4);
    root->left = left;
    root->right = right;
    
    Solution solu;
    solu.isValidBST(root);
          
//        cout <<"value="<< a << endl;
    return 0;
}
