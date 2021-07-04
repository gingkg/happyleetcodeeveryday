// leetcode_22_Generate_Parentheses.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：

输入：n = 1
输出：["()"]


提示：

1 <= n <= 8
*/


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        string track = {};
        backtrack(track, n);
        return result;
    }

    void backtrack(string track, int n) {
        if (track.size() == n * 2) {
            if (isValid(track, n)) {
                result.push_back(track);
            }
            return;
        }
        else {
            if (!isValid(track, n)) {
                return;
            }
        }
        char choose[] = { '(', ')' };
        for (char ch : choose) {
            track.push_back(ch);
            backtrack(track, n);
            track.pop_back();
        }
    }

    bool isValid(string str, int n) {
        int left = 0, right = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                left++;
            }
            else if (str[i] == ')') {
                right++;
            }
            if (right > left || right > n || left > n) return false;
        }
        return true;
    }

};


int main()
{
    cout << "Hello World!\n";
    int n = 3;
    Solution S;
    vector<string> res = S.generateParenthesis(n);
    for (vector<string>::iterator iter = res.begin(); iter != res.end(); iter++) {
        cout << *iter << endl;
    }
}

