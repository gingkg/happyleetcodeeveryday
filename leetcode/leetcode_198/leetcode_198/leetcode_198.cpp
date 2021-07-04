/*
198. 打家劫舍
你是一个专业的小偷，计划偷窃沿街的房屋。
每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

示例 1：

输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2：

输入：[2,7,9,3,1]
输出：12
解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 

提示：

0 <= nums.length <= 100
0 <= nums[i] <= 400

68 / 68 个通过测试用例
状态：通过
执行用时: 0 ms
内存消耗: 7.5 MB

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
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
};


int main()
{
    std::cout << "Hello World!\n";
    Solution S;
    vector<int> nums = { 2,7,9,3,1 };
    cout << S.rob(nums) << endl;

}

