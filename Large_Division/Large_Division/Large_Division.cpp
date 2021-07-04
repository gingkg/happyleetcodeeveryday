// Large_Division.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
大数求幂和取余
*/

#include <iostream>
using namespace std;


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


int main()
{
    int a = 3;
    int b = 45;
    int mode = 1000000007;
    cout << Mode(a, b, mode) << endl;
}

