﻿/*
1760. 袋子里最少数目的球
给你一个整数数组 nums ，其中 nums[i] 表示第 i 个袋子里球的数目。同时给你一个整数 maxOperations
你可以进行如下操作至多 maxOperations 次：

选择任意一个袋子，并将袋子里的球分到 2 个新的袋子中，每个袋子里都有 正整数 个球。
比方说，一个袋子里有 5 个球，你可以把它们分到两个新袋子里，分别有 1 个和 4 个球，或者分别有 2 个和 3 个球。
你的开销是单个袋子里球数目的 最大值 ，你想要 最小化 开销。

请你返回进行上述操作后的最小开销。

示例 1：

输入：nums = [9], maxOperations = 2
输出：3
解释：
- 将装有 9 个球的袋子分成装有 6 个和 3 个球的袋子。[9] -> [6,3] 。
- 将装有 6 个球的袋子分成装有 3 个和 3 个球的袋子。[6,3] -> [3,3,3] 。
装有最多球的袋子里装有 3 个球，所以开销为 3 并返回 3 。
示例 2：

输入：nums = [2,4,8,2], maxOperations = 4
输出：2
解释：
- 将装有 8 个球的袋子分成装有 4 个和 4 个球的袋子。[2,4,8,2] -> [2,4,4,4,2] 。
- 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,4,4,4,2] -> [2,2,2,4,4,2] 。
- 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,4,4,2] -> [2,2,2,2,2,4,2] 。
- 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2] 。
装有最多球的袋子里装有 2 个球，所以开销为 2 并返回 2 。
示例 3：

输入：nums = [7,17], maxOperations = 2
输出：7
 

提示：

1 <= nums.length <= 105
1 <= maxOperations, nums[i] <= 109

执行用时: 188 ms
内存消耗: 54.6 MB

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-limit-of-balls-in-a-bag
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int miniNumSize = 1;
        int numMax = *(max_element(nums.begin(), nums.end()));
        int left = 1;
        int right = numMax;
        int mid = 1;
        bool flag = false;
        while (left <= right) {
            mid = left + (right - left) / 2;
            int numOperations = 0;
            for (int num : nums) {
                numOperations += (num-1) / mid;
            }
            if (numOperations <= maxOperations) {
                miniNumSize = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return miniNumSize;
    }
};



int main()
{
    std::cout << "Hello World!\n";
    vector<int> nums{ 9 };
    int maxOperations = 2;
    Solution S;
    cout << S.minimumSize(nums, maxOperations) << endl;
}

