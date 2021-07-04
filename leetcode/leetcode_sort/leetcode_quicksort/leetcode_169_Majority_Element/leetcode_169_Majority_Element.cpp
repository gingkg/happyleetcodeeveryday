// leetcode_169_Majority_Element.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
169. 多数元素
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。



示例 1：

输入：[3,2,3]
输出：3
示例 2：

输入：[2,2,1,1,1,2,2]
输出：2


进阶：

尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void quickSort(vector<int>& nums, int start, int end) {
        if (end - start <= 1) return;

        // 这一步很重要
        int k = rand() % (end - start) + start; // 随机选一个作为我们的主元
        swap(nums[end - 1], nums[k]);

        int pivot = nums[end - 1];
        int i = start - 1;
        for (int j = start; j < end - 1; j++) {
            if (nums[j] < pivot) {
                i++;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[i + 1], nums[end - 1]);

        quickSort(nums, start, i + 1);
        quickSort(nums, i + 2, end);

        return;
    }

    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        quickSort(nums, 0, nums.size());
        return nums;
    }

    int majorityElement(vector<int>& nums) {
        nums = sortArray(nums);
        return nums[nums.size() / 2 + 1];
    }
};

int main()
{
    Solution S;
    vector<int> nums = { 2,2,1,1,1,2,2 };
    cout << S.majorityElement(nums) << endl;
}


