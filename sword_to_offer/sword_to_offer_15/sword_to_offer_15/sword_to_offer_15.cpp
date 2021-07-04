// sword_to_offer_15.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
剑指 Offer 15. 二进制中1的个数
请实现一个函数，输入一个整数（以二进制串形式），输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。



示例 1：

输入：00000000000000000000000000001011
输出：3
解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
示例 2：

输入：00000000000000000000000010000000
输出：1
解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
示例 3：

输入：11111111111111111111111111111101
输出：31
解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。


提示：

输入必须是长度为 32 的 二进制串 。
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        unsigned int m = 1;
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if ((n & m) == m) {
                res++;
            }
            m = (m << 1);
        }
        return res;
    }
};


class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            res++;
            n = n & (n - 1);
        }
        return res;
    }
};


int main()
{
    Solution2 S;
    uint32_t n = 0b11111111111111111111111111111111;
    cout << S.hammingWeight(n) << endl;
}

