// leetcode_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> twoSumTarget(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.size() - 1;
        vector<vector<int>> res;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            int left = nums[lo], right = nums[hi];
            if (sum < target) {
                while (lo < hi && nums[lo] == left) lo++;
            }
            else if (sum > target) {
                while (lo < hi && nums[hi] == right) hi--;
            }
            else {
                res.push_back({ nums[lo], nums[hi] });
                while (lo < hi && nums[lo] == left) lo++;
                while (lo < hi && nums[hi] == right) hi--;
            }
        }
        return res;
    }

    vector<vector<int>> twoSumTarget2(vector<int>& nums, int start, int target) {
        // sort(nums.begin(), nums.end());
        int lo = start, hi = nums.size() - 1;
        vector<vector<int>> res;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            int left = nums[lo], right = nums[hi];
            if (sum < target) {
                while (lo < hi && nums[lo] == left) lo++;
            }
            else if (sum > target) {
                while (lo < hi && nums[hi] == right) hi--;
            }
            else {
                res.push_back({ nums[lo], nums[hi] });
                while (lo < hi && nums[lo] == left) lo++;
                while (lo < hi && nums[hi] == right) hi--;
            }
        }
        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int start, int target) {
        vector<vector<int>> res;
        vector<vector<int>> temps;
        // sort(nums.begin(), nums.end());
        int N = nums.size();
        for (int i = start; i < N; i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            temps = twoSumTarget2(nums, i+1, target-nums[i]);
            for (vector<int>& temp : temps) {
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        return res;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<vector<int>> temps;
        sort(nums.begin(), nums.end());
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            temps = threeSum(nums, i + 1, target - nums[i]);
            for (vector<int>& temp : temps) {
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        return res;
    }


    vector<vector<int>> nSumTarget(vector<int>& nums, int n, int start, int target) {
        int sz = nums.size();
        vector<vector<int>> res;
        if (n < 2 || sz < n) return res;
        if (n == 2) {
            // 双指针
            int lo = start, hi = sz - 1;
            while (lo < hi) {
                int sum = nums[lo] + nums[hi];
                int left = nums[lo], right = nums[hi];
                if (sum < target) {
                    while (lo < hi && nums[lo] == left) lo++;
                }
                else if (sum > target) {
                    while (lo < hi && nums[hi] == right) hi--;
                }
                else {
                    res.push_back({ nums[lo], nums[hi] });
                    while (lo < hi && nums[lo] == left) lo++;
                    while (lo < hi && nums[hi] == right) hi--;
                }
                return res;
            }
        }
        else {
            for (int i = start; i < sz; i++) {
                if (i > start && nums[i] == nums[i - 1]) continue;
                vector<vector<int>> temps = nSumTarget(nums, n - 1, i + 1, target - nums[i]);
                for (vector<int>& temp : temps) {
                    temp.push_back(nums[i]);
                    res.push_back(temp);
                }
            }
            return res;
        }
        
    }

};


int main()
{
    std::cout << "Hello World!\n";
    vector<vector<int>> a = { {1,2},{3,4,5} };
    for (vector<int>& b : a) {
        b.push_back(3);
        break;
    }
    for (vector<int>& b : a) {
        for (int c : b) {
            cout << c << "";
        }
        cout << endl;
    }
}

