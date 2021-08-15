// leetcode_375_Guess_Number_Higher_or_Lower_II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
375. 猜数字大小 II
我们正在玩一个猜数游戏，游戏规则如下：

我从 1 到 n 之间选择一个数字，你来猜我选了哪个数字。

每次你猜错了，我都会告诉你，我选的数字比你的大了或者小了。

然而，当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。直到你猜到我选的数字，你才算赢得了这个游戏。

示例:

n = 10, 我选择了8.

第一轮: 你猜我选择的数字是5，我会告诉你，我的数字更大一些，然后你需要支付5块。
第二轮: 你猜是7，我告诉你，我的数字更大一些，你支付7块。
第三轮: 你猜是9，我告诉你，我的数字更小一些，你支付9块。

游戏结束。8 就是我选的数字。

你最终要支付 5 + 7 + 9 = 21 块钱。
给定 n ≥ 1，计算你至少需要拥有多少现金才能确保你能赢得这个游戏。
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


// 优化的暴力
class Solution {
public:
     int fun(int low, int high) {
         if (low >= high) return 0;
         int res = INT_MAX;
         for (int i = low + (high-low)/2; i <= high; i++) {
             int temp = i + max(fun(low, i - 1), fun(i + 1, high));
             res = min(res, temp);
         }
         return res;
    }

    int getMoneyAmount(int n) {
        return fun(1, n);
    }
};

// DP
class Solution2 {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int len = 2; len <= n; len++) {
            for (int start = 1; start <= n - len + 1; start++) {
                int minres = INT_MAX;
                for (int piv = start; piv < start + len - 1; piv++) {
                    int res = piv + max(dp[start][piv - 1], dp[piv + 1][start + len - 1]);
                    minres = min(res, minres);
                }
                dp[start][start + len - 1] = minres;
            }
        }
        return dp[1][n];
    }
};


int main()
{
    Solution2 S;
    int n = 10;
    cout << S.getMoneyAmount(n) << endl;
}

