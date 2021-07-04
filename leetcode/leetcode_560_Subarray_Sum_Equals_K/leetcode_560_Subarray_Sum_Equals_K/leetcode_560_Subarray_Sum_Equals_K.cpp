// leetcode_560_Subarray_Sum_Equals_K.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
560. 和为K的子数组
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :

数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        unordered_map<int, int> preSum;
        preSum.emplace(0, 1);

        int sum_i = 0;
        int sum_j;

        for (int i = 0; i < n; i++) {
            sum_i += nums[i];
            sum_j = sum_i - k;
            if (preSum.count(sum_j)) {
                res += preSum[sum_j];
            }
            preSum[sum_i] = preSum[sum_i] + 1;
        }

        return res;
    }
};


int main()
{
    std::cout << "Hello World!\n";
}

