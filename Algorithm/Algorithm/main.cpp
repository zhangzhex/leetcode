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

//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
//
//class Solution {
//public:
//    /**
//     *思路：利用前/中/后序i遍历二叉树生成字符串，判断包含关系。注意：空节点也需标出，得到唯一对应的树结构
//     */
//    bool isSubtree(TreeNode* s, TreeNode* t) {
//        if (s == NULL || t == NULL ) {
//            return false;
//        }
//        string str1 = treeToString(s);
//        string str2 = treeToString(t);
//
//        return (str1.find(str2) != string:: npos);
//    }
//
//    string treeToString(TreeNode *s) {
//        string str;
//        _treeToString(s, str);
//        return str;
//    }
//
//    void _treeToString(TreeNode *s, string &str) {
//
//        if (s->left == NULL) {
//            str = str + "#|";
//        } else {
//            _treeToString(s->left, str);
//        }
//
//        if (s->right == NULL) {
//            str = str + "#|";
//        } else {
//            _treeToString(s->right, str);
//        }
//
//        str = str + to_string(s->val) + "|";
//    }
//};


int uniquePaths(int m, int n) {
    if (m==0 || n==0) return 0;
    
    vector<vector<int>> value(m, vector<int>(n));
//    for (int i = 0; i < m; i++) {
//        value[i].resize(n);
//    }
    //初始化第0行
    value[0][0] = 0;
    for (int i = 1; i < m; i++) {
        value[i][0] = 1;
    }
    //初始化第0列
    for (int i = 1; i < n; i++) {
        value[0][i] = 1;
    }
    //value[i][j]表示走到该位置的总路径数
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            value[i][j] = value[i-1][j] + value[i][j-1];
//            cout <<"[" << i << "]"<<"[" << j << "]" << value[i][j] << endl;
//            value[i][j] = value[i-1][j] + value[i][j-1];
        }
    }
    return value[m-1][n-1];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a =uniquePaths(3, 2);
          
        cout <<"value="<< a << endl;
    return 0;
}
