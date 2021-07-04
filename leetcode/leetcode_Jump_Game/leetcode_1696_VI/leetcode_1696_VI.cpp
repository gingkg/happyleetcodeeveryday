// leetcode_1696_VI.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
1696. 跳跃游戏 VI
给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。

一开始你在下标 0 处。每一步，你最多可以往前跳 k 步，但你不能跳出数组的边界。也就是说，你可以从下标 i 跳到 [i + 1， min(n - 1, i + k)] 包含 两个端点的任意位置。

你的目标是到达数组最后一个位置（下标为 n - 1 ），你的 得分 为经过的所有数字之和。

请你返回你能得到的 最大得分 。



示例 1：

输入：nums = [1,-1,-2,4,-7,3], k = 2
输出：7
解释：你可以选择子序列 [1,-1,4,3] （上面加粗的数字），和为 7 。
示例 2：

输入：nums = [10,-5,-2,4,0,3], k = 3
输出：17
解释：你可以选择子序列 [10,4,3] （上面加粗数字），和为 17 。
示例 3：

输入：nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
输出：0


提示：

 1 <= nums.length, k <= 105
-104 <= nums[i] <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
using namespace std;

// 动态规划 + 优先队列
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[n - 1] = nums[n - 1];
        priority_queue < pair<int, int> > Q;
        Q.emplace(dp[n - 1], n - 1);

        for (int i = n-2; i >= 0; i--) {
            while (Q.top().second - i > k) {
                Q.pop();
            }

            dp[i] = nums[i] + Q.top().first;
            Q.emplace(dp[i], i);
        }
        return dp[0];
    }
};

// 动态规划 + 单调队列
class Solution2 {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[n - 1] = nums[n - 1];
        deque < pair<int, int> > Q;
        Q.emplace_back(dp[n - 1], n - 1);

        for (int i = n - 2; i >= 0; i--) {
            while (Q.front().second - i > k) {
                Q.pop_front();
            }

            dp[i] = nums[i] + Q.front().first;

            while (!Q.empty() && Q.back().first <= dp[i]) {
                Q.pop_back();
            }

            Q.emplace_back(dp[i], i);
        }
        return dp[0];
    }
};

int main()
{
    cout << "Hello World!\n";
    Solution2 S;
    vector<int> nums = { 1,-5,-20,4,-1,3,-6,-3 };
    int k = 2;
    cout << S.maxResult(nums, k) << endl;
}

