/*
46. 全排列
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

执行用时：4 ms
内存消耗：7.2 MB

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void backTrack(vector<vector<int>>& res, vector<int>& output, int first, int len) {
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; i++) {
            swap(output[i], output[first]);
            backTrack(res, output, first + 1, len);
            swap(output[i], output[first]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int L = nums.size();
        vector<vector<int>> res;
        backTrack(res, nums, 0, L);
        return res;
    }
};



int main()
{
    cout << "Hello World!\n";
   
    return 0;
}

