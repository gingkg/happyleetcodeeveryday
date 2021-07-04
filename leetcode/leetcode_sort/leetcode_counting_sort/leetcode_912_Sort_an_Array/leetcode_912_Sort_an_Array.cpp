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
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int, int> count;
        for (int num : nums) {
            count[num] = count[num] + 1;
        }
        auto iter = count.begin();
        int pos = 0;
        for (; iter != count.end(); iter++) {
            cout << iter->first << ": " << iter->second << endl;
            for (int i = 0; i < iter->second; i++) {
                nums[pos] = iter->first;
                pos++;
            }
        }
        return nums;
    }
};


int main()
{
    cout << "Hello World!\n";
    Solution S;
    vector<int> nums = { 5,2,3,1 };
    nums = S.sortArray(nums);
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

