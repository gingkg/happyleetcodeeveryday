// leetcode_45_II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
45. 跳跃游戏 II
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:

假设你总是可以到达数组的最后一个位置。
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;


// 动态规划
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        vector<int> dp(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = 1 + *min_element(dp.begin() + i+1, dp.begin() + i+1 + min(n - 1 - i, nums[i]));
        }
        return dp[0];
    }
};


// 贪心选择
class Solution2 {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int end = 0, farthest = 0;
        int res = 0;
        for (int i = 0; i < n -1; i++) {
            farthest = max(nums[i] + i, farthest);
            if (end == i) {
                res++;
                end = farthest;
            }
        }
        return res;
    }
};



int main()
{
    cout << "Hello World!\n";
    Solution2 S;
    vector<int> nums = { 2,3,1,1,4 };
    cout << S.jump(nums) << endl;
}

