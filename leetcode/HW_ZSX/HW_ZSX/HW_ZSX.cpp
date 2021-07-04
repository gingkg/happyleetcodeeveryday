// HW_ZSX.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    vector<int> solve(vector<vector<char>>& board) {
        int N = board.size();

        vector<int> res = { 0, 0 };

        while (true) {
            vector<vector<bool>> flag(N, vector<bool>(N, false));

            bool biaozhi = false;

            for (int k = 0; k < N * N; k++) {
                int i = k / N;
                int j = k % N;

                if (board[i][j] == 'B' && !flag[i][j]) {
                    // 上
                    if (0 <= i - 1 && i - 1 < N) {
                        if (board[i - 1][j] == 'R') {
                            board[i - 1][j] = 'B';
                            flag[i - 1][j] = true;
                            biaozhi = true;
                        }
                    }
                    // 下
                    if (0 <= i + 1 && i + 1 < N) {
                        if (board[i + 1][j] == 'R') {
                            board[i + 1][j] = 'B';
                            flag[i + 1][j] = true;
                            biaozhi = true;
                        }
                    }
                    // 左
                    if (0 <= j - 1 && j - 1 < N) {
                        if (board[i][j - 1] == 'R') {
                            board[i][j - 1] = 'B';
                            flag[i][j - 1] = true;
                            biaozhi = true;
                        }
                    }
                    // 右
                    if (0 <= j + 1 && j + 1 < N) {
                        if (board[i][j + 1] == 'R') {
                            board[i][j + 1] = 'B';
                            flag[i][j + 1] = true;
                            biaozhi = true;
                        }
                    }
                }
            }
            if (biaozhi) {
                res[0]++;
            }
            else {
                break;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'R') res[1]++;
            }
        }
        return res;
    }
};


int main()
{
    Solution S;

    int M, N;
    
    while (cin >> M >> N) {
        vector<vector<char>> board(M, vector<char>(N, 'E'));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board[i][j];
            }
        }

        vector<int> res = S.solve(board);
        cout << "[" <<res[0] << "," << res[1] << "]" << endl;
    }

    return 0;
}

