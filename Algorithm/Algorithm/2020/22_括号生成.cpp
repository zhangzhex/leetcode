//
//  22_括号生成.cpp
//  Algorithm
//
//  Created by zack on 2020/7/24.
//  Copyright © 2020 zack. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        dfs("((()))", 0, n, n, result, n);
        return result;
    }

    void dfs(string str, int depth, int leftRemain, int rightRemain, vector<string> &result, int &n) {
        if (depth == 2*n) {
            result.push_back(str);
            return;
        }

        if (leftRemain > 0) {
            str[depth] = '(';
            dfs(str, depth+1, leftRemain-1, rightRemain, result, n);
        }

        if (rightRemain > 0 && rightRemain != leftRemain) {
            str[depth] = ')';
            dfs(str, depth+1, leftRemain, rightRemain-1, result, n);
        }
    }
    
//        vector<string> generateParenthesis(int n) {
//            vector<string> result;
//
//            string str;
//            for (int i = 0; i < n; i++) {
//                str.push_back('(');
//            }
//            for (int i = 0; i < n; i++) {
//                str.push_back(')');
//            }
//
//            dfs(str, 0, result);
//            return result;
//        }
//
//        void dfs(string &str, int depth, vector<string> &result) {
//            // 最后一层
//            if (depth == str.size() - 1) {
//                string v(str);
//                result.push_back(v);
//            }
//
//            // 根据当前层数做交换
//            for (int i = depth; i < str.size(); i++) {
//                if (isRepeat(str, depth, i)) continue;
//                if (isInValid(str, depth, i)) continue;
//                swap(str, depth, i);
//                dfs(str, depth+1, result);
//                // 返回上一层，恢复位置
//                swap(str, depth, i);
//            }
//        }
//
//        void swap(string& str, int i, int j) {
//            int temp = str[i];
//            str[i] = str[j];
//            str[j] = temp;
//        }
//
//        bool isRepeat(string& str, int depth, int j) {
//            for (int i = depth; i < j; i++) {
//                if (str[i] == str[j]) return true;
//            }
//            return false;
//        }
//
//        bool isInValid(string& str, int depth, int j) {
//            int rightParenthesisCount = 0;
//            int leftParenthesisCount = 0;
//            for (int i = depth; i < str.size(); i++) {
//                if (str[i] == '(') {
//                    rightParenthesisCount++;
//                } else {
//                    leftParenthesisCount++;
//                }
//            }
//            // 只能是右括号
//            if (rightParenthesisCount == leftParenthesisCount) {
//                if (str[j] == '(') {
//                    return false;
//                }
//            }
//            // 可右可左括号
//            if (rightParenthesisCount < leftParenthesisCount) {
//                return false;
//            }
//
//          return true;
//      }
};
