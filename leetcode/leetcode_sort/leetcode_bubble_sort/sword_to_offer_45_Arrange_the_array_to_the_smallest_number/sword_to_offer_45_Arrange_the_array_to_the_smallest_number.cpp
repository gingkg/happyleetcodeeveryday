// sword_to_offer_45_Arrange_the_array_to_the_smallest_number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
剑指 Offer 45. 把数组排成最小的数
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。



示例 1:

输入: [10,2]
输出: "102"
示例 2:

输入: [3,30,34,5,9]
输出: "3033459"


提示:

0 < nums.length <= 100
说明:

输出结果可能非常大，所以你需要返回一个字符串而不是整数
拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isSwap(int a, int b) {
        int tempa = a, tempb = b;
        stack<int> A, B;
        if (a == 0) B.push(a);
        if (b == 0) A.push(b);
        while (a != 0) {
            B.push(a % 10);
            a = a / 10;
        }
        while (b != 0) {
            A.push(b % 10);
            b = b / 10;
        }
        a = tempa;
        b = tempb;
        if (a == 0) A.push(a);
        if (b == 0) B.push(b);
        while (b != 0) {
            B.push(b % 10);
            b = b / 10;
        }
        while (a != 0) {
            A.push(a % 10);
            a = a / 10;
        }

        while (!A.empty() || !B.empty()) {
            if (A.top() > B.top()) return true;
            if (A.top() < B.top()) return false;
            A.pop();
            B.pop();
        }
        return false;
    }

    string minNumber(vector<int>& nums) {
        int n = nums.size();
        string res = "";
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (isSwap(nums[j], nums[j + 1])) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        
        for (const auto& num : nums) {
            res.append(to_string(num));
            cout << num << " ";
        }
        cout << endl;
        return res;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<int> nums = { 824,938,1399,5607,6973,5703,9609,4398,8247 };
    Solution S;
    cout << S.minNumber(nums) << endl;
}

