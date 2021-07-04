// leetcode_398_Random_Pick_Index.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
398. 随机数索引
给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。 您可以假设给定的数字一定存在于数组中。

注意：
数组大小可能非常大。 使用太多额外空间的解决方案将不会通过测试。

示例 :

int[] nums = new int[] {1, 2, 3, 3, 3};
Solution solution = new Solution(nums);

// pick(3) 应该返回索引 2,3 或者 4。每个索引的返回概率应该相等。
solution.pick(3);

// pick(1) 应该返回 0。因为只有nums[0]等于1。
solution.pick(1);
*/



#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;


class Solution {
private:
    vector<int> nums;

public:
    Solution(vector<int>& nums) {
        this->nums = nums;
        srand(time(NULL));
    }

    int pick(int target) {
        int i = 0;
        int res = -1;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == target && rand() % (++i) == 0) {
                res = j;
            }
        }
        return res;
    }
};



int main()
{
    cout << "Hello World!\n";
    vector<int> nums = { 1,2,3,3,3 };
    int target = 3;
    Solution* obj = new Solution(nums);
    int param_1 = obj->pick(target);
    cout << param_1 << endl;

    return -1;
}






