/*
322. 零钱兑换
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

你可以认为每种硬币的数量是无限的。

 

示例 1：

输入：coins = [1, 2, 5], amount = 11
输出：3
解释：11 = 5 + 5 + 1

执行用时：72 ms
内存消耗：13.4 MB


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 数组⼤⼩为 amount + 1， 初始值也为 amount + 1
        vector<int> dp(amount + 1, amount + 1);
        // base case
        dp[0] = 0;
        for (int i = 0; i < dp.size(); i++) {
            // 内层 for 在求所有⼦问题 + 1 的最⼩值
            for (int coin : coins) {
                if (i - coin < 0) continue;
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }

        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};



int main()
{
    Solution S;
    vector<int> coins(1, 2);
    int amount = 12;

    cout << S.coinChange(coins, amount) << endl;

    cout << "Hello World!" << endl;

    return 0;
}
