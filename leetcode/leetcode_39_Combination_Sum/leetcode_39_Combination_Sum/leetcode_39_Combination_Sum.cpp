// leetcode_39_Combination_Sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
39. 组合总和
给定一个无重复元素的正整数数组 candidates 和一个正整数 target ，找出 candidates 中所有可以使数字和为目标数 target 的唯一组合。

candidates 中的数字可以无限制重复被选取。如果至少一个所选数字数量不同，则两种组合是唯一的。

对于给定的输入，保证和为 target 的唯一组合数少于 150 个。

示例 1：

输入: candidates = [2,3,6,7], target = 7
输出: [[7],[2,2,3]]
示例 2：

输入: candidates = [2,3,5], target = 8
输出: [[2,2,2,2],[2,3,3],[3,5]]
示例 3：

输入: candidates = [2], target = 1
输出: []
示例 4：

输入: candidates = [1], target = 1
输出: [[1]]
示例 5：

输入: candidates = [1], target = 2
输出: [[1,1]]


提示：

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate 中的每个元素都是独一无二的。
1 <= target <= 500
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    void trackback(vector<int>& candidates, int& target, vector<int>& track, int idx, int& sum, vector<vector<int>>& res) {
        if (idx >= candidates.size()) return;

        if (sum == target) {
            res.push_back(track);
            return;
        }
        else if (sum > target) {
            return;
        }

        trackback(candidates, target, track, idx + 1, sum, res);

        track.push_back(candidates[idx]);
        sum += candidates[idx];
        trackback(candidates, target, track, idx, sum, res);
        track.pop_back();
        sum -= candidates[idx];

        return;
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int sum = 0;
        vector<int> track;

        trackback(candidates, target, track, 0, sum, res);

        return res;
    }
};


int main()
{
    vector<int> candidates = { 2, 3, 6, 7 };
    int target = 7;
    Solution S;
    vector<vector<int>> res = S.combinationSum(candidates, target);

    for (auto&& vec : res) {
        for (auto&& v : vec) {
            cout << v << " ";
        }
        cout << endl;
    }

}


