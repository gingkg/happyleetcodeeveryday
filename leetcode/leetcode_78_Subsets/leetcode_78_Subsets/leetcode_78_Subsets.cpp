// leetcode_78_Subsets.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
78. 子集
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。



示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]


提示：

1 <= nums.length <= 10
-10 <= nums[i] <= 10
nums 中的所有元素 互不相同
*/

#include <iostream>
#include <vector>
using namespace std;

// 数学归纳
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return { {} };
        int x = nums.back();
        nums.pop_back();
        vector<vector<int>> temp = subsets(nums);
        int size = temp.size();
        for (int i = 0; i < size; i++) {
            temp.push_back(temp[i]);
            temp.back().push_back(x);
        }
        return temp;
    }
};


class Solution2 {
public:
    vector<vector<int>> result;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;
        backtrack(nums, 0, track);
        return result;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& track) {
        result.push_back(track);
        for (int i = start; i < nums.size(); i++) {
            // 做选择
            track.push_back(nums[i]);
            // 回溯
            backtrack(nums, i + 1, track);
            // 撤销选择
            track.pop_back();
        }
    }
};



int main()
{
    cout << "Hello World!\n";
    vector<int> nums = { 1,2,3 };
    Solution S;
   

}

