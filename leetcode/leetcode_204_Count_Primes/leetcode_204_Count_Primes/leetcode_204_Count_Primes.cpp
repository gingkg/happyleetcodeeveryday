// leetcode_204_Count_Primes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
204. 计数质数
统计所有小于非负整数 n 的质数的数量。



示例 1：

输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
示例 2：

输入：n = 0
输出：0
示例 3：

输入：n = 1
输出：0


提示：

0 <= n <= 5 * 106
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrim(n, true);

        for (int i = 2; i * i < n; i++) {
            if (isPrim[i]) {
                // i 的倍数不可能是素数了
                for (int j = i * i; j < n; j += i) {
                    isPrim[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrim[i]) count++;
        }
        return count;
    }
};

int main()
{
    cout << "Hello World!\n";
    Solution S;
    cout << S.countPrimes(900) << endl;
    
}

