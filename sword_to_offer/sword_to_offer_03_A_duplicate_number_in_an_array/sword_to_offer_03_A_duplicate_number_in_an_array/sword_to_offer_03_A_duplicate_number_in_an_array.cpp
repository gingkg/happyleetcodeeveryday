// sword_to_offer_22_A_duplicate_number_in_an_array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
剑指 Offer 03. 数组中重复的数字
找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3


限制：

2 <= n <= 100000
*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> index;
        for (int num : nums) {
            if (index.count(num)) {
                return num;
            }
            else {
                index[num] = 1;
            }
        }
        return -1;
    }
};

class Solution2 {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> index;
        for (int num : nums) {
            if (index.count(num)) {
                return num;
            }
            else {
                index.emplace(num);
            }
        }
        return -1;
    }
};


// 原地交换
class Solution3 {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                if (nums[nums[i]] == nums[i]) {
                    return nums[i];
                }
                else {
                    int temp = nums[i];
                    nums[i] = nums[temp];
                    nums[temp] = temp;
                }
            }
        }
    }
};


int main()
{
    Solution3 S;
    vector<int> nums = { 2, 3, 1, 0, 2, 5, 3 };
    cout << S.findRepeatNumber(nums) << endl;
}


