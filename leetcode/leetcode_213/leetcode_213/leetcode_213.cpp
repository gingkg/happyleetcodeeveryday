/*
213. 打家劫舍 II
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。



示例 1：

输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2：

输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 3：

输入：nums = [0]
输出：0


提示：

1 <= nums.length <= 100
0 <= nums[i] <= 1000

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    int robRaw(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) return 0;
        if (N == 1) return nums[0];
        if (N == 2) return max(nums[0], nums[1]);
        int output[2] = { 0, 0 };
        int m1 = max(nums[0], nums[1]);
        int m2 = nums[0];
        for (int i = 2; i < N; i++) {
            output[0] = m1;
            output[1] = m2 + nums[i];
            m1 = max(m1, max(output[0], output[1]));
            m2 = max(m2, output[0]);
        }
        return max(output[0], output[1]);
    }


    int rob(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) return 0;
        if (N == 1) return nums[0];
        int output[3] = { 0, 0, 0 };
        vector<int> temp1(nums.begin(), nums.end()-1);
        vector<int> temp2(nums.begin()+1, nums.end());
        vector<int> temp3(nums.begin()+1, nums.end() - 1);
        output[0] = robRaw(temp1);
        output[1] = robRaw(temp2);
        output[2] = robRaw(temp3);
        return max(max(output[0], output[1]), output[2]);
    }
};

int main()
{
    std::cout << "Hello World!\n";
    Solution S;
    vector<int> nums = {  };
    cout << S.rob(nums) << endl;
}

