// leetcode_56_Merge Intervals.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
56. 合并区间
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。



示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。


提示：

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
            return u[0] < v[0];
            });
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> res;

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            }
            else {
                res.push_back({ start, end });
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        res.push_back({ start, end });

        return res;
    }
};

int main()
{
    
}






