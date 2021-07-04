// sword_to_offer_14.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
剑指 Offer 14- I. 剪绳子
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

示例 1：

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
提示：

2 <= n <= 58
*/
/*
最优解是一道数学题，看解析：https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/mian-shi-ti-14-i-jian-sheng-zi-tan-xin-si-xiang-by/
重点两个推论：
基础是算术几何均值不等式
推论一： 将绳子 以相等的长度等分为多段 ，得到的乘积最大。
推论二： 尽可能将绳子以长度 33 等分为多段时，乘积最大。
切分规则：
最优： 3 。把绳子尽可能切为多个长度为 33 的片段，留下的最后一段绳子的长度可能为 0,1,20,1,2 三种情况。
次优： 2 。若最后一段绳子长度为 22 ；则保留，不再拆为 1+11+1 。
最差： 1 。若最后一段绳子长度为 11 ；则应把一份 3 + 13+1 替换为 2 + 22+2，因为 2 \times 2 > 3 \times 12×2>3×1。

作者：jyd
链接：https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/mian-shi-ti-14-i-jian-sheng-zi-tan-xin-si-xiang-by/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


如果不能思考出数学解，试试贪心。
*/




#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        int m = n / 3;
        int a = n % 3;
        if (a == 0) {
            return pow(3, m);
        }
        else if(a == 1){
            m = m - 1;
            return pow(3, m) * 2 * 2;
        }
        else if (a == 2) {
            return pow(3, m) * 2;
        }
        return -1;
    }
};


class Solution2 {
public:

    long long Mode(long long a, long long b, long long mode)
    {
        long long sum = 1;
        a = a % mode;

        while (b > 0) {
            if (b % 2 == 1)		//判断是否是奇数，是奇数的话将多出来的数事先乘如sum
                sum = (sum * a) % mode;

            b /= 2;
            a = (a * a) % mode;// 不断的两两合并再取模，减小a和b的规模
        }
        return sum;
    }


    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        int m = n / 3;
        int a = n % 3;
        int mode = 1000000007;
        if (a == 0) {
            return Mode(3, m, mode);
        }
        else if (a == 1) {
            m = m - 1;
            return (Mode(3,m,mode) * 2 * 2) % mode;
        }
        else if (a == 2) {
            return (Mode(3, m, mode) * 2) % mode;
        }
        return -1;
    }
};


int main()
{
    Solution2 S;
    int n = 120;
    cout << S.cuttingRope(n) << endl;
    cout << 865810542 * 3 << endl;
    cout << 1000000007 * 3 << endl;
    
}

