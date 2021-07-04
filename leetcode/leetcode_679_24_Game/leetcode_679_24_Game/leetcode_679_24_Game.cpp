// leetcode_679_24_Game.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
679. 24 点游戏
你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。

示例 1:

输入: [4, 1, 8, 7]
输出: True
解释: (8-4) * (7-1) = 24
示例 2:

输入: [1, 2, 1, 2]
输出: False
注意:

除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1 是不允许的。
你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。
*/


// float精度不足

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    double target = 24;
    double EPSION = 1e-6;

public:
    bool solve(vector<double>& cards) {
        int n = cards.size();
        if (n == 1) {
            return fabs(cards[0] - target) < EPSION;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                vector<double> restCards = {};
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) restCards.emplace_back(cards[k]);
                }
                // 选择
                double temp;
                // +
                if (j > i) {
                    temp = cards[i] + cards[j];
                    restCards.emplace_back(temp);
                    if (solve(restCards)) return true;
                    restCards.pop_back();
                }
                // -
                temp = cards[i] - cards[j];
                restCards.emplace_back(temp);
                if (solve(restCards)) return true;
                restCards.pop_back();
                // *
                if (j > i) {
                    temp = cards[i] * cards[j];
                    restCards.emplace_back(temp);
                    if (solve(restCards)) return true;
                    restCards.pop_back();
                }
                // /
                if (fabs(cards[j]) >= EPSION) {
                    temp = cards[i] / cards[j];
                    restCards.emplace_back(temp);
                    if (solve(restCards)) return true;
                    restCards.pop_back();
                }
            }
        }
        return false;
    }


    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(4, 0);
        for (int i = 0; i < cards.size(); i++) {
            nums[i] = cards[i];
        }
        return solve(nums);
    }
};


int main()
{
    Solution S;
    vector<int> cards = { 3, 3, 8, 8 };
    if (S.judgePoint24(cards)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}


