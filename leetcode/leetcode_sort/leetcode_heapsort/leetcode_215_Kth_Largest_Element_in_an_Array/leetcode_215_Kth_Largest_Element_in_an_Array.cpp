// leetcode_215_Kth_Largest_Element_in_an_Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
215. 数组中的第K个最大元素
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
*/



#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end(), greater<int>());
        sort_heap(nums.begin(), nums.end(), greater<int>());
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
        return nums[k-1];
    }
};

int main()
{
    cout << "Hello World!\n";
    Solution S;
    vector<int> nums = { 1, 2 };
    int k = 1;
    cout << S.findKthLargest(nums, k) << endl;
}


