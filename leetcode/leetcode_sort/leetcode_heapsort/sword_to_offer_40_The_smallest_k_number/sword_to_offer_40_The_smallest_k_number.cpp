// sword_to_offer_40_The_smallest_k_number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
剑指 Offer 40. 最小的k个数
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。



示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]


限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        make_heap(arr.begin(), arr.end());
        sort_heap(arr.begin(), arr.end());
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};

int main()
{
    Solution S;
    vector<int> nums = { 3,2,1 };
    int k = 2;
    vector<int> res = S.getLeastNumbers(nums, k);
    for (int r : res) {
        cout << r << " ";
    }
    cout << endl;

}

