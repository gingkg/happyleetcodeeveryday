// leetcode_164_Maximum_Gap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
164. 最大间距
给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。

如果数组元素个数小于 2，则返回 0。

示例 1:

输入: [3,6,9,1]
输出: 3
解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
示例 2:

输入: [10]
输出: 0
解释: 数组元素个数小于 2，因此返回 0。
说明:

你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxbit(vector<int>& data) //辅助函数，求数据的最大位数
    {
        int maxData = data[0];              ///< 最大数
        /// 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
        for (auto num: data)
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

    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        radixsort(nums);
        cout << endl;
        int maxGap = nums[1] - nums[0];
        for (int i = 2; i < n; i++) {
            int gap = nums[i] - nums[i - 1];
            if (maxGap < gap) maxGap = gap;
        }
        return maxGap;
    }
};

int main()
{
    vector<int> nums = { 3,6,9,1 };
    Solution S;
    cout << S.maximumGap(nums) << endl;
}

