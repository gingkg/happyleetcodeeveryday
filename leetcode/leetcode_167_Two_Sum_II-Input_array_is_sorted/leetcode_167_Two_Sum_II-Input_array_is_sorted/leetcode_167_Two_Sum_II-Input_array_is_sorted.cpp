// leetcode_167_Two_Sum_II-Input_array_is_sorted.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
167. 两数之和 II - 输入有序数组
给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。

函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1 开始计数 ，所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。

你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。


示例 1：

输入：numbers = [2,7,11,15], target = 9
输出：[1,2]
解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
示例 2：

输入：numbers = [2,3,4], target = 6
输出：[1,3]
示例 3：

输入：numbers = [-1,0], target = -1
输出：[1,2]


提示：

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers 按 递增顺序 排列
-1000 <= target <= 1000
仅存在一个有效答案
*/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        int sum = 0;
        while (left < right) {
            sum = numbers[left] + numbers[right];
            if (sum < target) left++;
            if (sum > target) right--;
            if (sum == target) return { left, right };
        }
    }
};


class Solution2 {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        char temp;
        while (left < right) {
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};


int main()
{
    cout << "Hello World!\n";
    vector<int> numbers = { 2,7,11,15 };
    int target = 9;
    Solution S;
    vector<int> res = S.twoSum(numbers, target);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    vector<char> s = { 'h','e','l','l','o' };
    Solution2 S2;
    S2.reverseString(s);
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;

    return 0;


}




