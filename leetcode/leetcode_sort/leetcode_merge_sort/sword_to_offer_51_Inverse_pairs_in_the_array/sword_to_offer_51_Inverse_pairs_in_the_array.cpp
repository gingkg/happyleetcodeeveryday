// sword_to_offer_51_Inverse_pairs_in_the_array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
剑指 Offer 51. 数组中的逆序对
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。



示例 1:

输入: [7,5,6,4]
输出: 5


限制：

0 <= 数组长度 <= 50000
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& temp, int L, int R) {
        if (R - L <= 1) return 0;
        int count = 0;
        int mid = L + (R - L) / 2;
        count = count + mergeSort(nums, temp, L, mid) + mergeSort(nums, temp, mid, R);
        // 合并
        int i = L, j = mid, pos = 0;
        while (i < mid && j < R) {
            if (nums[i] <= nums[j]) {
                temp[pos] = nums[i];
                i++;
                count += j - mid;
            }
            else {
                temp[pos] = nums[j];
                j++;
            }
            pos++;
        }
        for (; i < mid; i++) {
            temp[pos++] = nums[i];
            count += j - mid;
        }
        for (; j < R; j++) {
            temp[pos++] = nums[j];
        }
        copy(temp.begin(), temp.begin() + (R-L), nums.begin() + L);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        return mergeSort(nums, temp, 0, nums.size());
    }
};

int main()
{
    std::cout << "Hello World!\n";
    Solution S;
    vector<int> nums = { 7,5,6,4 };
    cout << S.reversePairs(nums) << endl;
}

