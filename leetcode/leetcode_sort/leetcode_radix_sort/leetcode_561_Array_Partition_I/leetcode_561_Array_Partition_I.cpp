// leetcode_561_Array_Partition_I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
561. 数组拆分 I
给定长度为 2n 的整数数组 nums ，你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从 1 到 n 的 min(ai, bi) 总和最大。

返回该 最大总和 。



示例 1：

输入：nums = [1,4,3,2]
输出：4
解释：所有可能的分法（忽略元素顺序）为：
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
所以最大总和为 4
示例 2：

输入：nums = [6,2,6,5,1,2]
输出：9
解释：最优的分法为 (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9


提示：

1 <= n <= 104
nums.length == 2 * n
-104 <= nums[i] <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxbit(vector<int>& data) //辅助函数，求数据的最大位数
    {
        int maxData = data[0];              ///< 最大数
        /// 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
        for (auto num : data)
        {
            if (maxData < num)
                maxData = num;
        }
        int d = 1;
        int p = 10;
        while (maxData >= p)
        {
            //p *= 10; // Maybe overflow
            maxData /= 10;
            ++d;
        }
        return d;
    }

    void radixsort(vector<int>& data) //基数排序
    {
        int n = data.size();
        int d = maxbit(data);
        vector<int> tmp(n);
        vector<int> count(10); //计数器

        int i, j, k;
        int radix = 1;
        for (i = 1; i <= d; i++) //进行d次排序
        {
            for (j = 0; j < 10; j++)
                count[j] = 0; //每次分配前清空计数器
            for (j = 0; j < n; j++)
            {
                k = (data[j] / radix) % 10; //统计每个桶中的记录数
                count[k]++;
            }
            for (j = 1; j < 10; j++)
                count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
            for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
            {
                k = (data[j] / radix) % 10;
                tmp[count[k] - 1] = data[j];
                count[k]--;
            }
            for (j = 0; j < n; j++) //将临时数组的内容复制到data中
                data[j] = tmp[j];
            radix = radix * 10;
        }
    }

    int arrayPairSum(vector<int>& nums) {
        // radixsort(nums);
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i = i + 2) {
            res = res + nums[i];
        }
        return res;
    }
};

int main()
{
    vector<int> nums = { 6214, -2290, 2833, -7908 };
    Solution S;
    cout << S.arrayPairSum(nums) << endl;
}

