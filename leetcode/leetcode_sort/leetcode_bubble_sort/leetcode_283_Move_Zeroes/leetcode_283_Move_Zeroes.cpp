// leetcode_283_Move_Zeroes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
283. 移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSwap(int a, int b) {
        if (a == 0 && b == 0) return false;
        if (a == 0 && b != 0) return true;
        if (a != 0 && b == 0) return false;
        return false;
    }

    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (isSwap(nums[j], nums[j + 1])) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }
};

int main()
{
    cout << "Hello World!\n";
    Solution S;
    vector<int> nums = { 0, 1, 0, 3, 12 };
    S.moveZeroes(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

