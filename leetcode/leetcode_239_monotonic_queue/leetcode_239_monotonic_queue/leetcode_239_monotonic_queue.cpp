// leetcode_239_monotonic_queue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
239. 滑动窗口最大值
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。



示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
示例 2：

输入：nums = [1], k = 1
输出：[1]
示例 3：

输入：nums = [1,-1], k = 1
输出：[1,-1]
示例 4：

输入：nums = [9,11], k = 2
输出：[11]
示例 5：

输入：nums = [4,-2], k = 2
输出：[4]


提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length

*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

template<typename T>
class MonotonicQueue {
private:
    deque<T> data;
public:
    void push(T n) {
        while (!data.empty() && data.back() < n) {
            data.pop_back();
        }
        data.push_back(n);
    }
    T max() {
        return data.front();
    }
    void pop(T n) {
        //之所以要判断 data.front() == n ， 是因为我们想删除的队头元素 n 可能已
        //经被「压扁」 了， 这时候就不⽤删除了
        if (!data.empty() && data.front() == n)
            data.pop_front();
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        MonotonicQueue<int> window;
        for (int i = 0; i < nums.size(); i++) {
            if (i < k - 1) {
                window.push(nums[i]);
            }
            else {
                window.push(nums[i]);
                res.push_back(window.max());
                window.pop(nums[i - k + 1]);
            }
        }
        return res;
    }
};



int main()
{
    cout << "Hello World!\n";
    vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
    vector<int> res;
    int k = 3;
    Solution S;
    res = S.maxSlidingWindow(nums, k);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

}

