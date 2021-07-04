// leetcode_20_Valid_Parentheses.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。


示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false
示例 4：

输入：s = "([)]"
输出：false
示例 5：

输入：s = "{[]}"
输出：true


提示：

1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成
*/

#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

// 练习栈的使用
class Solution {
public:
    char leftOf(char c) {
        switch (c)
        {
        case '}':
            return '{';
        case ']':
            return '[';
        case ')':
            return '(';
        default:
            throw "符号不合法!";
        }
    }

    bool isValid(string s) {
        int n = s.size();
        stack<int> left;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                left.push(s[i]);
            }
            else {
                if (!left.empty() && leftOf(s[i]) == left.top()) {
                    left.pop();
                }
                else {
                    return false;
                }
            }
        }

        if (left.empty()) {
            return true;
        }
        else {
            return false;
        }
        
    }
};


int main()
{
    std::cout << "Hello World!\n";
}

