// leetcode_51_N_Queue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
51. N 皇后

n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。


提示：
1 <= n <= 9
皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。

执行用时：12 ms
内存消耗：7.3 MB

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-queens
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
private:
    vector<vector<string>> res;
public:
    // 路径： board 中⼩于 row 的那些⾏都已经成功放置了皇后
    // 选择列表： 第 row ⾏的所有列都是放置皇后的选择
    // 结束条件： row 超过 board 的最后⼀⾏
    void backTrack(vector<string>& board, int row, int n) {
        // 触发结束条件
        if (row == n) {
            res.emplace_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            // 排除不合法选择
            if (!isValid(board, row, col, n)) {
                continue;
            }
            board[row][col] = 'Q';
            backTrack(board, row + 1, n);
            board[row][col] = '.';
        }
    }

    /* 是否可以在 board[row][col] 放置皇后？ */
    bool isValid(vector<string>& board, int row, int col, int n) {
        // 检查列是否有皇后互相冲突
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        // 检查右上⽅是否有皇后互相冲突
        for (int i = 1; i <= min(row, n - 1 - col); i++) {
            if (board[row - i][col + i] == 'Q')
                return false;
        }
        // 检查左上⽅是否有皇后互相冲突
        for (int i = 1; i <= min(row, col); i++) {
            if (board[row - i][col - i] == 'Q')
                return false;
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        // '.' 表⽰空， 'Q' 表⽰皇后， 初始化空棋盘
        vector<string> board(n, string(n, '.'));
        backTrack(board, 0, n);
        return res;
    }
};


int main()
{
    Solution S;
    vector<vector<string>> res;
    int n = 11;
    res = S.solveNQueens(n);
    cout << "解法数量: " << res.size() << endl;
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < n; j++) {
            if (j == n - 1) {
                cout << "\"" << res[i][j] << "\"";
            }
            else {
                cout << "\"" << res[i][j] << "\",";
            }
        }
        if (i == res.size() - 1) {
            cout << "]]\n";
        }
        else {
            cout << "],\n ";
        }
    }
    return 0;
}



