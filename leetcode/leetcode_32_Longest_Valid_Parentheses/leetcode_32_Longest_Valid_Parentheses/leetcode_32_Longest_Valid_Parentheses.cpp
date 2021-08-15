// leetcode_32_Longest_Valid_Parentheses.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
32. 最长有效括号
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。



示例 1：

输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"
示例 2：

输入：s = ")()())"
输出：4
解释：最长有效括号子串是 "()()"
示例 3：

输入：s = ""
输出：0


提示：

0 <= s.length <= 3 * 104
s[i] 为 '(' 或 ')'
*/

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n);
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '(') continue;
            if (s[i - 1] == '(') {
                dp[i] = i >= 2 ? dp[i - 2] + 2 : 2;
            }
            else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i - 1] + 2 + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};


int main()
{
    Solution S;
    string s = ")()())";
    cout << S.longestValidParentheses(s) << endl;
}


