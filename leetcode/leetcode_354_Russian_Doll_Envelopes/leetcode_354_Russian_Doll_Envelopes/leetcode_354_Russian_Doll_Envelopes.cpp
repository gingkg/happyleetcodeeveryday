// leetcode_354_Russian_Doll_Envelopes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
354. 俄罗斯套娃信封问题
给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。

当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

注意：不允许旋转信封。


示例 1：

输入：envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出：3
解释：最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
示例 2：

输入：envelopes = [[1,1],[1,1],[1,1]]
输出：1


提示：

1 <= envelopes.length <= 5000
envelopes[i].length == 2
1 <= wi, hi <= 104
*/


// 最长增长子序列
// 宽度升序，高度降序

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> list;
        list.push_back(nums[0]);
        int len = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > list.back()) {
                list.push_back(nums[i]);
                len++;
            }
            else if (nums[i] == list.back()) {
                continue;
            }
            else {
                // 二分查找
                int left = 0, right = len - 1;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (list[mid] < nums[i]) {
                        left = mid + 1;
                    }
                    else {
                        right = mid;
                    }
                }
                list[right] = nums[i];
            }
        }
        return len;
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const auto& u, const auto& v) {
            if (u[0] < v[0]) {
                return true;
            }
            else if (u[0] > v[0]) {
                return false;
            }
            else {
                if (u[1] < v[1]) {
                    return false;
                }
                else {
                    return true;
                }
            }
            });

        vector<int> height;
        for (int i = 0; i < envelopes.size(); i++) {
            height.push_back(envelopes[i][1]);
        }

        return lengthOfLIS(height);
    }
};


int main()
{
    vector<vector<int>> envelopes = { {5,4},{6,4},{6,7},{2,3} };
    Solution S;
    cout << S.maxEnvelopes(envelopes) << endl;

}
