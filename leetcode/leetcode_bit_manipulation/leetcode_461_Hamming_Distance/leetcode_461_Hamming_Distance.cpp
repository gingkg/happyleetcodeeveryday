﻿// leetcode_461_Hamming_Distance.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
461. 汉明距离
两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

给出两个整数 x 和 y，计算它们之间的汉明距离。

注意：
0 ≤ x, y < 231.

示例:

输入: x = 1, y = 4

输出: 2

解释:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

上面的箭头指出了对应二进制位不同的位置。
*/


#include <iostream>
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
};


int main()
{
    cout << "Hello World!\n";
    Solution S;
    cout << S.hammingDistance(1, 4) << endl;
}

