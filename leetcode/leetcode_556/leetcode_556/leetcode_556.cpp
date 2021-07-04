// leetcode_556.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
556. 下一个更大元素 III
给你一个正整数 n ，请你找出符合条件的最小整数，其由重新排列 n 中存在的每位数字组成，并且其值大于 n 。
如果不存在这样的正整数，则返回 -1 。

注意 ，返回的整数应当是一个 32 位整数 ，如果存在满足题意的答案，但不是 32 位整数 ，同样返回 -1 。

示例 1：
输入：n = 12
输出：21

示例 2：
输入：n = 21
输出：-1

提示：
1 <= n <= 231 - 1
*/


#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public: 
    vector<int> decompose(int n) {
        vector<int> res;
        while (n > 0) {
            res.push_back(n % 10);
            n = n / 10;
        }
        // sort(res.rbegin(), res.rend());
        reverse(res.begin(), res.end());
        return res;
    }

    int nextGreaterElement(int n) {
        if (n < 10) return -1;
        vector<int> res = decompose(n);
        long long int ans = 0;
        int left=-1, right=-1;
        for (int i = 0; i < res.size(); i++) {
            cout << res[i];
        }
        cout << endl;
        for (int i = res.size() - 1; i > 0; i--) {
            if (res[i - 1] < res[i]) {
                left = i - 1;
                break;
            }
        }
        if (left == -1) return -1;
        for (int i = res.size()-1; i > left; i--) {
            if (res[i] > res[left]) {
                right = i;
                break;
            }
        }
        int swap = res[left];
        res[left] = res[right];
        res[right] = swap;
        vector<int> res_(res.begin() + left + 1, res.end());
        sort(res_.begin(), res_.end());
        for (int i = 0; i < res_.size(); i++) {
            res[left + i + 1] = res_[i];
        }
        for (int i = 0; i < res.size(); i++) {
            ans = ans + res[i] * pow(10, res.size()-1 - i);
        }

        if (ans > INT_MAX) {
            return -1;
        }
        else {
            return ans;
        }
    }
};

int main()
{
    cout << "Hello World!\n";
    Solution S;
    int n = 12;
    cout << S.nextGreaterElement(n) <<endl;

    
    return 0;
}
