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

后序赋值实现插入比直接插入删除省时间

*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*void directInsertionSort(vector<int>& nums, int gap) {
        int n = nums.size();
        for (int i = 0; i < gap; i++) {
            for (int j = i + gap; j < n; j = j + gap) {
                int k = j - gap;
                if (nums[j] >= nums[k]) continue;
                for (; k >= 0; k = k - gap) {
                    if (nums[k] <= nums[j]) break;
                }

                nums.insert(nums.begin() + (k + gap), nums[j]);
                nums.erase(nums.begin() + (j + 1));
            }
        }
    }*/

    void directInsertionSort(vector<int>& nums, int gap) {
        int n = nums.size();
        for (int i = 0; i < gap; i++) {
            for (int j = i + gap; j < n; j = j + gap) {
                int cur = nums[j];
                int k = j - gap;
                while (k >= 0 && cur < nums[k]) {
                    nums[k + gap] = nums[k];
                    k = k - gap;
                }
                nums[k + gap] = cur;
            }
        }
    }


    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int gap = n;
        while (gap > 1) {
            gap = gap / 3 + 1;
            directInsertionSort(nums, gap);
            cout << "==================================" << endl;
            for (int num : nums) {
                cout << num << " ";
            }
            cout << endl;
        }
        return nums;
    }
};

int main()
{
    cout << "Hello World!\n";
    Solution S;
    vector<int> nums = { -4,0,7,4,9,-5,-1,0,-7,-1 };
    nums = S.sortArray(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
}
