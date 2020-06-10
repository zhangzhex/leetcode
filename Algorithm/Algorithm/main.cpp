//
//  main.cpp
//  Algorithm
//
//  Created by zack on 2020/4/11.
//  Copyright © 2020 zack. All rights reserved.
//

#include <iostream>
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
    /**
     *思路：利用前/中/后序i遍历二叉树生成字符串，判断包含关系。注意：空节点也需标出，得到唯一对应的树结构
     */
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL || t == NULL ) {
            return false;
        }
        string str1 = treeToString(s);
        string str2 = treeToString(t);
        
        return (str1.find(str2) != string:: npos);
    }
    
    string treeToString(TreeNode *s) {
        string str;
        _treeToString(s, str);
        return str;
    }
    
    void _treeToString(TreeNode *s, string &str) {
        
        if (s->left == NULL) {
            str = str + "#|";
        } else {
            _treeToString(s->left, str);
        }
        
        if (s->right == NULL) {
            str = str + "#|";
        } else {
            _treeToString(s->right, str);
        }
        
        str = str + to_string(s->val) + "|";
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode *root = new TreeNode(10);
    TreeNode *left = new TreeNode(9);
    TreeNode *right = new TreeNode(8);
    root->left = left;
    root->right = right;
    
    
    Solution slu;
    
//    string str = to_string(10);
    
    string str = slu.treeToString(root);
 
//    if (NULL == NULL ) {
//    std::cout << "equeal";
//    }
    
    std::cout << str;
    return 0;
}
