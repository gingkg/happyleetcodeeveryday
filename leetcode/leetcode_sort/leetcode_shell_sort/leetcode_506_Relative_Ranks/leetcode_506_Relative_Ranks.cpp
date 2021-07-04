// leetcode_506_Relative_Ranks.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
506. 相对名次
给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold Medal", "Silver Medal", "Bronze Medal"）。

(注：分数越高的选手，排名越靠前。)

示例 1:

输入: [5, 4, 3, 2, 1]
输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal" and "Bronze Medal").
余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
提示:

N 是一个正整数并且不会超过 10000。
所有运动员的成绩都不相同。
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void directInsertionSort(vector<int>& nums, int gap) {
        int n = nums.size();
        for (int i = 0; i < gap; i++) {
            for (int j = i + gap; j < n; j = j + gap) {
                int cur = nums[j];
                int k = j - gap;
                while (k >= 0 && cur > nums[k]) {
                    nums[k + gap] = nums[k];
                    k = k - gap;
                }
                nums[k + gap] = cur;
            }
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int gap = n / 2;
        while (gap >= 1) {
            directInsertionSort(nums, gap);
            gap /= 2;
        }
        return nums;
    }

    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> scoreCpoy = score;
        vector<string> res;
        scoreCpoy = sortArray(scoreCpoy);
        for (int s : score) {
            auto iter = find(scoreCpoy.begin(), scoreCpoy.end(), s);
            int r = (iter - scoreCpoy.begin()) + 1;
            if (r == 1) res.push_back("Gold Medal");
            if (r == 2) res.push_back("Silver Medal");
            if (r == 3) res.push_back("Bronze Medal");
            if (r > 3) res.push_back(to_string(r));
        }
        return res;
    }
};

int main()
{
    cout << "Hello World!\n";
    Solution S;
    vector<int> score = { 5, 4, 3, 2, 1 };
    vector<string> res = S.findRelativeRanks(score);
    for (string i : res) {
        cout << i << " ";
    }
    cout << endl;
}



