// leetcode_739_Daily_Temperatures.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
739. 每日温度
请根据每日 气温 列表 temperatures ，请计算在每一天需要等几天才会有更高的温度。如果气温在这之后都不会升高，请在该位置用 0 来代替。

示例 1:

输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]
示例 2:

输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]
示例 3:

输入: temperatures = [30,60,90]
输出: [1,1,0]


提示：

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);

        stack<int> monoStack;

        for (int i = 0; i < n; i++) {
            if (monoStack.empty()) {
                monoStack.push(i);
            }
            else {
                while (!monoStack.empty() && temperatures[i] > temperatures[monoStack.top()]) {
                    res[monoStack.top()] = i - monoStack.top();
                    monoStack.pop();
                }
                monoStack.push(i);
            }
        }

        return res;
    }
};


int main()
{
    vector<int> temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
    Solution S;
    vector<int> res = S.dailyTemperatures(temperatures);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
}


