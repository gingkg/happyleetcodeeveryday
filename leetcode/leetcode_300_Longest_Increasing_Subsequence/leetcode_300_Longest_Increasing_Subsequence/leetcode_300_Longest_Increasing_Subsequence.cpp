// leetcode_300_Longest_Increasing_Subsequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
300. 最长递增子序列
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。


示例 1：

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
示例 2：

输入：nums = [0,1,0,3,2,3]
输出：4
示例 3：

输入：nums = [7,7,7,7,7,7,7]
输出：1


提示：

1 <= nums.length <= 2500
-104 <= nums[i] <= 104


进阶：

你可以设计时间复杂度为 O(n2) 的解决方案吗？
你能将算法的时间复杂度降低到 O(n log(n)) 吗?
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
方法一：动态规划
思路与算法

定义 \textit{ dp }[i]dp[i] 为考虑前 ii 个元素，以第 ii 个数字结尾的最长上升子序列的长度，注意 \textit{ nums }[i]nums[i] 必须被选取。

我们从小到大计算 \textit{ dp }dp 数组的值，在计算 \textit{ dp }[i]dp[i] 之前，我们已经计算出 \textit{ dp }[0 \ldots i - 1]dp[0…i−1] 的值，则状态转移方程为：

\textit{ dp }[i] = \max(\textit{ dp }[j]) + 1, \text{ 其中 } \, 0 \leq j < i \, \text{ 且 } \, \textit{ num }[j] < \textit{ num }[i]
    dp[i] = max(dp[j]) + 1, 其中0≤j < i且num[j] < num[i]

    即考虑往 \textit{ dp }[0 \ldots i - 1]dp[0…i−1] 中最长的上升子序列后面再加一个 \textit{ nums }[i]nums[i]。由于 \textit{ dp }[j]dp[j] 代表 \textit{ nums }[0 \ldots j]nums[0…j] 中以 \textit{ nums }[j]nums[j] 结尾的最长上升子序列，所以如果能从 \textit{ dp }[j]dp[j] 这个状态转移过来，那么 \textit{ nums }[i]nums[i] 必然要大于 \textit{ nums }[j]nums[j]，才能将 \textit{ nums }[i]nums[i] 放在 \textit{ nums }[j]nums[j] 后面以形成更长的上升子序列。

    最后，整个数组的最长上升子序列即所有 \textit{ dp }[i]dp[i] 中的最大值。

    \text{ LIS }_{ \textit{length} } = \max(\textit{ dp }[i]), \text{ 其中 } \, 0\leq i < n
    LIS
    length
    ​
    = max(dp[i]), 其中0≤i < n

    作者：LeetCode - Solution
    链接：https ://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            int value = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && value < dp[j]) {
                    value = dp[j];
                }
            }
            dp[i] = value+1;
        }
        auto maxPosi = max_element(dp.begin(), dp.end());
        return *maxPosi;
    }
};



/*
方法二：贪心 + 二分查找
思路与算法

考虑一个简单的贪心，如果我们要使上升子序列尽可能的长，则我们需要让序列上升得尽可能慢，因此我们希望每次在上升子序列最后加上的那个数尽可能的小。

基于上面的贪心思路，我们维护一个数组 d[i]d[i] ，表示长度为 ii 的最长上升子序列的末尾元素的最小值，用 \textit{len}len 记录目前最长上升子序列的长度，起始时 lenlen 为 11，d[1] = \textit{nums}[0]d[1]=nums[0]。

同时我们可以注意到 d[i]d[i] 是关于 ii 单调递增的。因为如果 d[j] \geq d[i]d[j]≥d[i] 且 j < ij<i，我们考虑从长度为 ii 的最长上升子序列的末尾删除 i-ji−j 个元素，那么这个序列长度变为 jj ，且第 jj 个元素 xx（末尾元素）必然小于 d[i]d[i]，也就小于 d[j]d[j]。那么我们就找到了一个长度为 jj 的最长上升子序列，并且末尾元素比 d[j]d[j] 小，从而产生了矛盾。因此数组 dd 的单调性得证。

我们依次遍历数组 \textit{nums}nums 中的每个元素，并更新数组 dd 和 lenlen 的值。如果 \textit{nums}[i] > d[\textit{len}]nums[i]>d[len] 则更新 len = len + 1len=len+1，否则在 d[1 \ldots len]d[1…len]中找满足 d[i - 1] < \textit{nums}[j] < d[i]d[i−1]<nums[j]<d[i] 的下标 ii，并更新 d[i] = \textit{nums}[j]d[i]=nums[j]。

根据 dd 数组的单调性，我们可以使用二分查找寻找下标 ii，优化时间复杂度。

最后整个算法流程为：

设当前已求出的最长上升子序列的长度为 \textit{len}len（初始时为 11），从前往后遍历数组 \textit{nums}nums，在遍历到 \textit{nums}[i]nums[i] 时：

如果 \textit{nums}[i] > d[\textit{len}]nums[i]>d[len] ，则直接加入到 dd 数组末尾，并更新 \textit{len} = \textit{len} + 1len=len+1；

否则，在 dd 数组中二分查找，找到第一个比 \textit{nums}[i]nums[i] 小的数 d[k]d[k] ，并更新 d[k + 1] = \textit{nums}[i]d[k+1]=nums[i]。

以输入序列 [0, 8, 4, 12, 2][0,8,4,12,2] 为例：

第一步插入 00，d = [0]d=[0]；

第二步插入 88，d = [0, 8]d=[0,8]；

第三步插入 44，d = [0, 4]d=[0,4]；

第四步插入 1212，d = [0, 4, 12]d=[0,4,12]；

第五步插入 22，d = [0, 2, 12]d=[0,2,12]。

最终得到最大递增子序列长度为 33。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class Solution2 {
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
                int left = 0, right = len-1;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (list[mid] < nums[i]) {
                        left = mid+1;
                    }
                    else {
                        right = mid;
                    }
                }
                list[right] = nums[i];
            }
            for (int j = 0; j < list.size(); j++) {
                cout << list[j] << " ";
            }
            cout << endl;
        }
        return len;
    }
};


int main()
{
    vector<int> nums = { 4, 10, 4, 3, 8, 9 };
    Solution1 S;
    cout << S.lengthOfLIS(nums) << endl;
}

