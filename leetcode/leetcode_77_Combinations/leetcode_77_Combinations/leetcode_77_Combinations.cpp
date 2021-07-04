// leetcode_77_Combinations.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
77. 组合
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        vector<int> track;
        trackback(n, k, 1, track);
        return result;
    }
    void trackback(int n, int k, int start, vector<int>& track) {
        if (track.size() == k) {
            result.push_back(track);
            return;
        }
        for (int i = start; i <= n; i++) {
            // 做选择
            track.push_back(i);
            // 回溯
            trackback(n, k, i + 1, track);
            // 撤销选择
            track.pop_back();
        }
    }
};


int main()
{
    std::cout << "Hello World!\n";
}


