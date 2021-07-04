// leetcode_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
1. 两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。



示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]


提示：

2 <= nums.length <= 103
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index.emplace(nums[i], i);
        }
        for (int i = 0; i < n; i++) {
            int other = target - nums[i];
            //  如果 other 存在且不是 nums[i] 本⾝
            if (index.count(other) && index.at(other) != i) {
                return { i, index.at(other) };
            }
        }
        return {-1, -1};
    }
};

int main()
{
    cout << "----------------1----------------\n";
    vector<int> nums = { 3,1,3,6 };
    int target = 6;
    Solution S;
    vector<int> res = S.twoSum(nums, target);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
