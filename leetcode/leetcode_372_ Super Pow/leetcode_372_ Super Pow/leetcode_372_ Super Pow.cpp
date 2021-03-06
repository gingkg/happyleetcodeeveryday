// leetcode_372_ Super Pow.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
372. 超级次方
你的任务是计算 ab 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。



示例 1：

输入：a = 2, b = [3]
输出：8
示例 2：

输入：a = 2, b = [1,0]
输出：1024
示例 3：

输入：a = 1, b = [4,3,3,8,5,2]
输出：1
示例 4：

输入：a = 2147483647, b = [2,0,0]
输出：1198


提示：

1 <= a <= 231 - 1
1 <= b.length <= 2000
0 <= b[i] <= 9
b 不含前导 0
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int base = 1337;

    // 计算 a 的 k 次⽅然后与 base 求模的结果
    int myPow(int a, int k) {
        if (k == 0) return 1;
        a %= base;
        if (k % 2 == 1) {
            // k 是奇数
            return (a * myPow(a, k - 1)) % base;
        }
        else {
            // k 是偶数
            int sub = myPow(a, k / 2);
            return (sub * sub) % base;
        }

        //// 对因⼦求模
        //a %= base;
        //int res = 1;
        //for (int _ = 0; _ < k; _++) {
        //    res *= a;
        //    // 对乘法结果求模
        //    res %= base;
        //}
        //return res;
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last = b.back();
        b.pop_back();

        int part1 = myPow(a, last);
        int part2 = myPow(superPow(a, b), 10);
        // 对因⼦求模
        return (part1 * part2) % base;
    }
};

int main()
{
    cout << "Hello World!\n";
}

