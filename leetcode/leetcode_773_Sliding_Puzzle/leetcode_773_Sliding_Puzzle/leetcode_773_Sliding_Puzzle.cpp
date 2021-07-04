// leetcode_773_Sliding_Puzzle.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
773. 滑动谜题
在一个 2 x 3 的板上（board）有 5 块砖瓦，用数字 1~5 来表示, 以及一块空缺用 0 来表示.

一次移动定义为选择 0 与一个相邻的数字（上下左右）进行交换.

最终当板 board 的结果是 [[1,2,3],[4,5,0]] 谜板被解开。

给出一个谜板的初始状态，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。

示例：

输入：board = [[1,2,3],[4,0,5]]
输出：1
解释：交换 0 和 5 ，1 步完成
输入：board = [[1,2,3],[5,4,0]]
输出：-1
解释：没有办法完成谜板
输入：board = [[4,1,2],[5,0,3]]
输出：5
解释：
最少完成谜板的最少移动次数是 5 ，
一种移动路径:
尚未移动: [[4,1,2],[5,0,3]]
移动 1 次: [[4,1,2],[0,5,3]]
移动 2 次: [[0,1,2],[4,5,3]]
移动 3 次: [[1,0,2],[4,5,3]]
移动 4 次: [[1,2,0],[4,5,3]]
移动 5 次: [[1,2,3],[4,5,0]]
输入：board = [[3,2,4],[1,5,0]]
输出：14
提示：

board 是一个如上所述的 2 x 3 的数组.
board[i][j] 是一个 [0, 1, 2, 3, 4, 5] 的排列.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isEnd(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != i * 3 + j + 1 && (!(i == m-1 && j == n-1))) {
                    return false;
                }
            }
        }
        return true;
    }

    vector<vector<vector<int>>> getState(vector<vector<int>>& board) {
        vector<vector<vector<int>>> res;
        vector<vector<int>> state;
        int m = board.size(), n = board[0].size();
        int a = 0, b = 0;
        //获取0的位置
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0) {
                    a = i;
                    b = j;
                    break;
                }
            }
        }
        // 获取所有可行状态
        // 上
        if (a - 1 >= 0) {
            state = board;
            state[a][b] = state[a-1][b];
            state[a-1][b] = 0;
            res.push_back(state);
        }
        //下
        if (a + 1 < m) {
            state = board;
            state[a][b] = state[a + 1][b];
            state[a + 1][b] = 0;
            res.push_back(state);
        }
        //左
        if (b - 1 >= 0) {
            state = board;
            state[a][b] = state[a][b-1];
            state[a][b-1] = 0;
            res.push_back(state);
        }
        //右
        if (b + 1 < n) {
            state = board;
            state[a][b] = state[a][b+1];
            state[a][b+1] = 0;
            res.push_back(state);
        }
        return res;
    }


    int slidingPuzzle(vector<vector<int>>& board) {
        queue<vector<vector<int>>> Q;
        set<vector<vector<int>>> visited;
        // unordered_set<vector<vector<int>>> visited;
        int step = 0;
        Q.push(board);
        vector<vector<int>> start = board;
        visited.insert(start);

        while (!Q.empty()) {
            int L = Q.size();
            for (int i = 0; i < L; i++) {
                vector<vector<int>> cur = Q.front();
                Q.pop();
                if (isEnd(cur)) {
                    return step;
                }
                // 获取可行动作
                vector<vector<vector<int>>> allState = getState(cur);
                // 扩散
                for (int k = 0; k < allState.size(); k++) {
                    if (!visited.count(allState[k])) {
                        Q.push(allState[k]);
                        visited.insert(allState[k]);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> board = { {4,1,2},{5, 0, 3} };
    cout << S.slidingPuzzle(board) << endl;
}
