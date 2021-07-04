/*
8. 字符串转换整数(atoi)
请你来实现一个 atoi 函数，使其能将字符串转换成整数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：

如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0 。

注意：

本题中的空白字符只包括空格字符 ' ' 。
假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  231 − 1 或 −231 。
 

示例 1:

输入: "42"
输出: 42

执行用时: 0 ms
内存消耗: 7.2 MB

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-to-integer-atoi
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
using namespace std;


class Solution {
private:
    string set = "+-0123456789";
    bool isPositive = true;
    double x = 0;
    int y[11] = { 0,0,0,0,0,0,0,0,0,0,0 };

public:
    void trim(string& s) {
        if (!s.empty()) {
            s.erase(0, s.find_first_not_of(' '));
            s.erase(s.find_last_not_of(' ') + 1);
        }
    }

    int myAtoi(string s) {
        // 去除开头结尾的空字符
        trim(s);
        // 判断是否字符串为空
        if (!s.empty()) {
            int L = s.size(); // 字符串长度
            // 判断第一个字符是否非法
            if (set.find(s[0]) != string::npos) {
                // 判断正负号
                if (s[0] == '+') {
                    isPositive = true;
                    s = s.substr(1, L-1);
                }
                else if (s[0] == '-') {
                    isPositive = false;
                    s = s.substr(1, L-1);
                }
                // 处理开头是0的情况
                s.erase(0, s.find_first_not_of('0'));
                if (!s.empty()) {
                    s = s.substr(0, 11);
                    L = s.size();
                    int num = 0;
                    int flag = L;
                    for (int i = 0; i < L; i++) {
                        // 判断是不是数字
                        num = int(s[i] - '0');
                        if (num >= 0 && num < 10) {
                            y[i] = num;
                        }
                        else
                        {
                            flag = i;
                            break;
                        }
                    }
                    for (int i = 0; i < flag; i++) {
                        x = x + pow(10, i) * y[flag - i - 1];
                    }
                    if (!isPositive) {
                        x = -x;
                    }
                    if (x < -pow(2,31)) {
                        return int(-pow(2, 31));
                    }
                    else if(x > pow(2, 31)-1)
                    {
                        return int(pow(2, 31)-1);
                    }
                    else {
                        return int(x);
                    }
                }
                else {
                    return 0;
                }  
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
    }
};



int helper(vector<int>& memo, int n) {
    if (n == 1 || n == 2) return 1;
    if (memo[n] != 0) return memo[n];
    memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
    return memo[n];
}


int fib(int N) {
    if (N < 1) return 0;
    vector<int> memo(N + 1, 0);
    return helper(memo, N);
}

int fib2(int N) {
    vector<int> dp(N + 1, 0);
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[N];
}


int fib3(int n) {
    if (n == 2 || n == 1)
        return 1;
    int prev = 1, curr = 1;
    for (int i = 3; i <= n; i++) {
        int sum = prev + curr;
        prev = curr;
        curr = sum;
    } 
    return curr;
}


int main()
{
    string s = "21474836460";
    Solution S1;
    int c = S1.myAtoi(s);

    cout << c << endl;

    cout << fib(20) << endl;
    cout << fib2(20) << endl;
    cout << fib3(20) << endl;

    return 0;

}

