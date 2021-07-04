// sword_to_offer_13_The_range_of_motion_of_the_robot.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
剑指 Offer 13. 机器人的运动范围
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？



示例 1：

输入：m = 2, n = 3, k = 1
输出：3
示例 2：

输入：m = 3, n = 1, k = 0
输出：1
提示：

1 <= n,m <= 100
0 <= k <= 20
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        // 使用临时变量 visited 记录格子是否被访问过
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // 开始深度优先遍历
        return dfs(0, 0, m, n, k, visited);
    }

    int dfs(int i, int j, int m, int n, int k, vector<vector<bool>>& visited) {
        // 行列索引越界 
        if (i >= m || j >= n) return 0;
        // 数位和超出目标值 k ，即不满足行坐标和列坐标的数位之和小于 k 的格子
        if (k < sum(i, j)) return 0;
        // 已经被访问过的重复格子
        if (visited[i][j]) return 0;
        //机器人进入了一个新格子，标注这个格子被访问过
        visited[i][j] = true;
        //沿着当前格子的右边和下边继续访问
        return 1 + dfs(i + 1, j, m, n, k, visited) + dfs(i, j + 1, m, n, k, visited);
    }

    //计算两个坐标数字的和
    int sum(int i, int j) {
        int sum = 0;
        while (i != 0) {
            // 通过求余和取整的操作来计算
            sum += i % 10;
            i /= 10;
        }
        while (j != 0) {
            sum += j % 10;
            j /= 10;
        }
        return sum;
    }

};




int main()
{
    cout << "Hello World!\n";
    int m = 2, n = 3, k = 1;
    Solution S;
    cout << S.movingCount(m, n, k) << endl;
}

