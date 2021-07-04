// leetcode_912_Sort_an_Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
912. 排序数组
给你一个整数数组 nums，请你将该数组升序排列。



示例 1：

输入：nums = [5,2,3,1]
输出：[1,2,3,5]
示例 2：

输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]


提示：

1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000
*/
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    void quickSort(vector<int>& nums, int start, int end) {
        if (end - start <= 1) return;

        // 这一步很重要
        int k = rand() % (end - start) + start; // 随机选一个作为我们的主元
        swap(nums[end-1], nums[k]);

        int pivot = nums[end-1];
        int i = start - 1;
        for (int j = start; j < end - 1; j++) {
            if (nums[j] < pivot) {
                i++;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[i + 1], nums[end - 1]);

        
        cout << "----------------------------" << endl;
        cout << i << endl;
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;

        quickSort(nums, start, i+1);
        quickSort(nums, i + 2, end);

        return;
    }

    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        quickSort(nums, 0, nums.size());
        return nums;
    }
};

int main()
{
    Solution S;
    // vector<int> nums = { -4,-5,-1,-7,-1,0,0,7,4,9 };
    vector<int> nums = { 5,1,1,2,0,0 };
    nums = S.sortArray(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

