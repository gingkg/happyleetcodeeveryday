// leetcode_43_Multiply_Strings.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
43. 字符串相乘
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
*/


#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        int carryBit;
        vector<vector<int>> temps;
        vector<int> temp;
        stack<int> S;
        string res = "";

        for (int i = n1-1;i>=0;i--) {
            temp.clear();
            carryBit = 0;
            for (int j = n2 - 1; j >= 0; j--) {
                int ans = (int(num1[i])-48) * (int(num2[j])-48) + carryBit;
                if (ans < 10) {
                    carryBit = 0;
                    S.push(ans);
                }
                else {
                    carryBit = ans / 10;
                    S.push(ans % 10);
                }
            }
            S.push(carryBit);
            while (!S.empty()) {
                temp.push_back(S.top());
                S.pop();
            }
            temps.push_back(temp);
        }

        vector<int>::iterator iter;
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n1 - 1 - i; j++) {
                iter = temps[i].begin();
                temps[i].insert(iter, 0);
            }
            for (int j = 0; j < i; j++) {
                temps[i].push_back(0);
            }
        }

        carryBit = 0;
        for (int i = n2 + n1 - 1; i >= 0; i--) {
            int ans = carryBit;
            for (int j = 0; j < n1; j++) {
                ans += temps[j][i];
            }
            carryBit = ans / 10;
            res = to_string(ans % 10) + res;
        }

        while (!res.empty() && res[0] == '0') {
            res.erase(0, 1);
        }

        if (res.empty()) res = '0';

        return res;

    }
};



int main()
{
    cout << "Hello World!\n";
    string num1 = "123", num2 = "456";
    Solution S;
    cout << S.multiply(num1, num2) << endl;

    return 0;
}

