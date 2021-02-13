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
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

class Solution {
public:
        vector<string> generateParenthesis(int n) {
            vector<string> result;
            
            string str;
            for (int i = 0; i < n; i++) {
                str.push_back('(');
            }
            for (int i = 0; i < n; i++) {
                str.push_back(')');
            }
            
            dfs(str, 0, result);
            return result;
        }
        
        void dfs(string &str, int depth, vector<string> &result) {
            // 最后一层
            if (depth == str.size() - 1) {
                string v(str);
                result.push_back(v);
            }
            
            // 根据当前层数做交换
            for (int i = depth; i < str.size(); i++) {
                if (isRepeat(str, depth, i)) continue;
                if (isValid(str, depth, i) == false) continue;
                swap(str, depth, i);
                dfs(str, depth+1, result);
                // 返回上一层，恢复位置
                swap(str, depth, i);
            }
        }
        
        void swap(string& str, int i, int j) {
            int temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
        
        bool isRepeat(string& str, int depth, int j) {
            for (int i = depth; i < j; i++) {
                if (str[i] == str[j]) return true;
            }
            return false;
        }
    
        bool isValid(string& str, int depth, int j) {
          
            //
            int rightParenthesisCount = 0;
            int leftParenthesisCount = 0;
            for (int i = depth; i < str.size(); i++) {
                if (str[i] == '(') {
                    rightParenthesisCount++;
                } else {
                    leftParenthesisCount++;
                }
            }
            // 只能是右括号
            if (rightParenthesisCount == leftParenthesisCount) {
                if (str[j] == '(') {
                    return true;
                }
            }
            // 可右可左括号
            if (rightParenthesisCount < leftParenthesisCount) {
                return true;
            }

          return false;
      }
};





int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a = 10;
    
    int & ref = a;
    ref = 20;
    
//    Solution solu;
//    solu.generateParenthesis(3);
          
    cout << a << endl;
    return 0;
}
