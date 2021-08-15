// leetcode_84_Largest_Rectangle_in_Histogram.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
84. 柱状图中最大的矩形
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。



示例 1:



输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10
示例 2：



输入： heights = [2,4]
输出： 4


提示：

1 <= heights.length <=105
0 <= heights[i] <= 104
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;



// 单调栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);

        stack<int> monoStack;

        for (int i = 0; i < n; i++) {
            while (!monoStack.empty() && heights[monoStack.top()] >=  heights[i]) {
                monoStack.pop();
            }
            if (monoStack.empty()) {
                left[i] = -1;
            }
            else {
                left[i] = monoStack.top();
            }
            monoStack.push(i);
        }

        monoStack = stack<int>();
        for (int i = n-1; i >= 0; --i) {
            while (!monoStack.empty() && (heights[monoStack.top()] >= heights[i])) {
                monoStack.pop();
            }
            if (monoStack.empty()) {
                right[i] = n;
            }
            else {
                right[i] = monoStack.top();
            }
            monoStack.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int ans = heights[i] * (right[i] - left[i] - 1);
            if (ans > res) {
                res = ans;
            }
        }

        return res;
    }
};




int main()
{
    Solution S;
    vector<int> heights = { 4,2,0,3,2,4,3,4 };
    cout << S.largestRectangleArea(heights) << endl;
}

