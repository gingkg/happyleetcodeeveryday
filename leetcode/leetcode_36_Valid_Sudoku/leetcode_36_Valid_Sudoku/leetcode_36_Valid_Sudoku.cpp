// leetcode_36_Valid_Sudoku.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
36. 有效的数独
请你判断一个 9x9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

注意：

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。


示例 1：


输入：board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
输出：true
示例 2：

输入：board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
输出：false
解释：除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。 但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。


提示：

board.length == 9
board[i].length == 9
board[i][j] 是一位数字或者 '.'
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<unordered_set<char>> rows(m);
        vector<unordered_set<char>> colums(n);
        vector<unordered_set<char>> boxs((m/3)*(n/3));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') continue;

                if (!rows[i].count(board[i][j])) {
                    rows[i].emplace(board[i][j]);
                }
                else {
                    return false;
                }

                if (!colums[j].count(board[i][j])) {
                    colums[j].emplace(board[i][j]);
                }
                else {
                    return false;
                }

                if (!boxs[(i / 3) * 3 + j / 3].count(board[i][j])) {
                    boxs[(i / 3) * 3 + j / 3].emplace(board[i][j]);
                }
                else {
                    return false;
                }
            }
        }
        
        return true;
    }
};


int main()
{
    std::cout << "Hello World!\n";
}

