// leetcode_1034_Coloring_A_Border.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
1034. 边框着色
给出一个二维整数网格 grid，网格中的每个值表示该位置处的网格块的颜色。

只有当两个网格块的颜色相同，而且在四个方向中任意一个方向上相邻时，它们属于同一连通分量。

连通分量的边界是指连通分量中的所有与不在分量中的正方形相邻（四个方向上）的所有正方形，或者在网格的边界上（第一行/列或最后一行/列）的所有正方形。

给出位于 (r0, c0) 的网格块和颜色 color，使用指定颜色 color 为所给网格块的连通分量的边界进行着色，并返回最终的网格 grid 。



示例 1：

输入：grid = [[1,1],[1,2]], r0 = 0, c0 = 0, color = 3
输出：[[3, 3], [3, 2]]
示例 2：

输入：grid = [[1,2,2],[2,3,2]], r0 = 0, c0 = 1, color = 3
输出：[[1, 3, 3], [2, 3, 3]]
示例 3：

输入：grid = [[1,1,1],[1,1,1],[1,1,1]], r0 = 1, c0 = 1, color = 2
输出：[[2, 2, 2], [2, 1, 2], [2, 2, 2]]


提示：

1 <= grid.length <= 50
1 <= grid[0].length <= 50
1 <= grid[i][j] <= 1000
0 <= r0 < grid.length
0 <= c0 < grid[0].length
1 <= color <= 1000


执行结果：通过
执行用时：12 ms, 在所有 C++ 提交中击败了99.36%的用户
内存消耗：13.1 MB, 在所有 C++ 提交中击败了93.59%的用户
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool fillBorder(vector<vector<int>>& grid, int r0, int c0, int neWcolor, int oldColor) {
        int m = grid.size(), n = grid[0].size();
        if (neWcolor == oldColor) return false;
        if (0 <= r0 && r0 < m && 0 <= c0 && c0 < n){
            if (grid[r0][c0] == -1) {
                return false;
            }
            if (grid[r0][c0] == neWcolor) {
                return false;
            }
            if (grid[r0][c0] != oldColor) {
                return true;
            }
        }
        else {
            return true;
        }

        grid[r0][c0] = -1;

        bool down = fillBorder(grid, r0 + 1, c0, neWcolor, oldColor);
        bool up = fillBorder(grid, r0 - 1, c0, neWcolor, oldColor);
        bool right = fillBorder(grid, r0, c0 + 1, neWcolor, oldColor);
        bool left = fillBorder(grid, r0, c0 - 1, neWcolor, oldColor);

        if (down || up || right || left) {
            grid[r0][c0] = neWcolor;
        }
        else {
            grid[r0][c0] = oldColor;
        }

        return false;
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        fillBorder(grid, r0, c0, -2, grid[r0][c0]);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == -2) grid[i][j] = color;
            }
        }
        return grid;
    }
};

int main()
{
    cout << "Hello World!\n";
    vector<vector<int>> image = { {1,2,1,2,1,2},{2,2,2,2,1,2},{1,2,2,2,1,2} };
    int sr = 1, sc = 3, newColor = 1;
    Solution S;
    vector<vector<int>> res = S.colorBorder(image, sr, sc, newColor);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

