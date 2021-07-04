/*
416. 分割等和子集
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:
每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:
输入: [1, 5, 11, 5]
输出: true
解释: 数组可以分割成 [1, 5, 5] 和 [11].


示例 2:
输入: [1, 2, 3, 5]
输出: false
解释: 数组不能分割成两个元素和相等的子集.
*/
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


class Solution {
public:
    vector<int> res;

    bool dp(vector<int> nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            cout << i << endl;
            vector<int> numsCopy = nums;
            numsCopy.erase(numsCopy.begin() + i);
            if (target - nums[i] > 0) {
                if (dp(numsCopy, target - nums[i])) {
                    res.push_back(nums[i]);
                    return true;
                }
                //return dp(numsCopy, target - nums[i]);
            }
            else if (target - nums[i] < 0) {
                continue;
            }
            else {
                res.push_back(nums[i]);
                return true;
            }
        }
        return false;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        cout << sum << endl;
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        return dp(nums, target);
    }
};



class Solution2 {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= 0; j--) {
                if (j - nums[i] >= 0) {
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
            }
        }
        return dp[target];
    }
};


int main()
{
    cout << "Hello World!\n";
    Solution2 S;
    vector<int> nums = { 100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,97 };
    if (S.canPartition(nums)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    /*
    for (vector<int>::iterator itr = S.res.begin(); itr != S.res.end(); itr++) {
        cout << *itr << "";
    }
    cout << endl;*/

}

