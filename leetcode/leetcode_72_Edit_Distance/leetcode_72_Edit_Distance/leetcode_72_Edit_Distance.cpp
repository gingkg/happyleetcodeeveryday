// leetcode_72_Edit_Distance.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
72. 编辑距离
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符


示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')


提示：

0 <= word1.length, word2.length <= 500
word1 和 word2 由小写英文字母组成
*/

// 还是动态规划，奇怪，奇怪，难以理解

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(int a, int b, int c)
    {
        a = min(a, b);
        b = min(b, c);
        return min(a, b);
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) dp[i][0] = i;
        for (int j = 1; j <= m; j++) dp[0][j] = j;

        int cost = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) cost = 0;
                else cost = 1;
                dp[i][j] = findMin(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost);
            }
        }

        return dp[n][m];
    }
};

int main()
{
    Solution S;
    string word1 = "intention";
    string word2 = "execution";
    cout << S.minDistance(word1, word2) << endl;
}

