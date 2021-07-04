// leetcode_477_Total_Hamming_Distance.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
477. 汉明距离总和
两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。

计算一个数组中，任意两个数之间汉明距离的总和。

示例 :

输入: 4, 14, 2

输出 : 6

解释 : 在二进制表示中，4表示为0100，14表示为1110，2表示为0010。（这样表示是为了体现后四位之间关系）
所以答案为：
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
注意 :

    数组中元素的范围为从 0到 10 ^ 9。
    数组的长度不超过 10 ^ 4。
*/


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int res = 0;
        while (z != 0) {
            z = z & (z - 1);
            res++;
        }
        return res;
    }

    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                res += hammingDistance(nums[i], nums[j]);
            }
        }
        return res;
    }
};


class Solution2 {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        vector<int> cnt(32, 0);
        for (auto&& num : nums) {
            int i = 0;
            while (num > 0) {
                cnt[i] += (num & 0x1);
                num >>= 1;
                i++;
            }
        }

        for (auto&& k : cnt) {
            res += k * (n - k);
        }
        return res;
    }
};


int main()
{
    cout << "Hello World!\n";
    vector<int> nums = { };
    Solution2 S;
    cout << S.totalHammingDistance(nums) << endl;
}

