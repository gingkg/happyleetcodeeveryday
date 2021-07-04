// leetcode_392_Is_Subsequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
392. 判断子序列
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

进阶：

如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

致谢：

特别感谢 @pbrother 添加此问题并且创建所有测试用例。



示例 1：

输入：s = "abc", t = "ahbgdc"
输出：true
示例 2：

输入：s = "axc", t = "ahbgdc"
输出：false


提示：

0 <= s.length <= 100
0 <= t.length <= 10^4
两个字符串都只由小写字符组成。
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int> data, int target) {
        int left = 0, right = data.size() - 1;
        if (target >= data[right]) return -1;
        int mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (target >= data[mid]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return data[left];
    }

    bool isSubsequence(string s, string t) {
        // 构造索引
        unordered_map<char, vector<int>> index;
        for (int i = 0; i < t.size(); i++) {
            if (index.count(t[i])) {
                index[t[i]].push_back(i);
            }
            else {
                index[t[i]] = { i };
            }
        }

        unordered_map<char, vector<int>>::iterator iter = index.begin();
        for (; iter != index.end(); iter++) {
            cout << iter->first << ": [ ";
            for (const auto& i : iter->second) {
                cout << i << " ";
            }
            cout << "]" << endl;
        }

        int p = -1;
        for (char c : s) {
            if (!index.count(c)) return false;
            p = binarySearch(index[c], p);
            if (p < 0) {
                return false;
            }
        }
        
        return true;
    }
};



int main()
{
    Solution S;
    string s = "axc", t = "ahbgdc";
    cout << S.isSubsequence(s, t) << endl;
}

