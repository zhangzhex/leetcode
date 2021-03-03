//
//  113 路径总和 II.cpp
//  Algorithm
//
//  Created by 熊章哲 on 2021/3/3.
//  Copyright © 2021 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        
        vector<int> vec;
        vec.push_back(root->val);
        int currentSum = root->val;
        dfs(root, targetSum, result, vec, currentSum);
        return result;
    }
    
    void dfs(TreeNode *root, int targetSum, vector<vector<int>> &result, vector<int>& path, int currentSum) {
        // 最后一层为结果
        if (root->left == nullptr && root->right == nullptr) {
            if (currentSum == targetSum) {
                result.push_back(path);
            }
            return;
        }
        
        // 遍历当前所有选择
        if (root->left != nullptr) {
            currentSum += root->left->val;
            path.push_back(root->left->val);
            dfs(root->left, targetSum, result, path, currentSum);
            currentSum -= root->left->val;
            path.pop_back();
        }
        
        if (root->right != nullptr) {
            currentSum += root->right->val;
            path.push_back(root->right->val);
            dfs(root->right, targetSum, result, path, currentSum);
            currentSum -= root->right->val;
            path.pop_back();
        }
    }
};
