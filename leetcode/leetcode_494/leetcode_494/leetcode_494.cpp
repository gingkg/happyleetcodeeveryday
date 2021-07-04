// leetcode_494.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
494. 目标和
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。



示例：

输入：nums: [1, 1, 1, 1, 1], S: 3
输出：5
解释：

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。


提示：

数组非空，且长度不会超过 20 。
初始的数组的和不会超过 1000 。
保证返回的最终结果能被 32 位整数存下。
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <string>
using namespace std;


// 动归
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S || (S + sum) % 2 != 0) return 0;
        int target = (S + sum) / 2;
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int s = target; s >= 0; s--) {
                if (s - nums[i] >= 0) {
                    dp[s] = dp[s] + dp[s - nums[i]];
                }
            }
        }
        return dp[target];
    }
};


// 回溯
class Solution2 {
public:
    int res = 0;
    void backtrack(vector<int>& nums, int i, int rest) {
        if (i == nums.size()) {
            if (rest == 0) {
                res++;
            }
            return;
        }
        rest += nums[i];
        backtrack(nums, i + 1, rest);
        rest -= nums[i];

        rest -= nums[i];
        backtrack(nums, i + 1, rest);
        rest += nums[i];

    }
    int findTargetSumWays(vector<int>& nums, int S) {
        backtrack(nums, 0, S);
        return res;
    }
};

// 回溯 + 消除重叠子问题
class Solution3 {
public:
    unordered_map<string, int> memo;
    int dp(vector<int>& nums, int i, unsigned int rest) {
        if (i == nums.size()) {
            if (rest == 0) {
                return 1;
            }
            return 0;
        }
        string key = to_string(i) + "," + to_string(rest);
        if (memo.count(key)) {
            return memo[key];
        }
        int res = dp(nums, i + 1, rest - nums[i]) + dp(nums, i + 1, rest + nums[i]);
        cout << res << endl;
        memo[key] = res;
        return res;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        return dp(nums, 0, S);
    }
};


int main()
{
    std::cout << "Hello World!\n";
    string key = to_string(2) + "," + to_string(6);
    cout << key << endl;
    
    Solution3 S;
    vector<int> nums = { 2, 107, 109, 113, 127, 131, 137, 3, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 47, 53 };
    int t = 2147483647;
    cout << S.findTargetSumWays(nums, t) << endl;
    
}
