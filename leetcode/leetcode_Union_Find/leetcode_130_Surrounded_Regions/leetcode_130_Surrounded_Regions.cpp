// leetcode_130_Surrounded_Regions.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
130. 被围绕的区域
给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。


示例 1：


输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
示例 2：

输入：board = [["X"]]
输出：[["X"]]


提示：

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] 为 'X' 或 'O'
*/


#include <iostream>
#include <vector>
using namespace std;

class UF {
private:
    int count;
    vector<int> parent;
    vector<int> size;

public:
    UF(int n) {
        count = n;
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

public:
    /* 将 p 和 q 连接 */
    void connet(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;

        // ⼩树接到⼤树下⾯， 较平衡
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        count--;
    }

    /* 判断 p 和 q 是否连通 */
    bool connected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    /* 返回图中有多少个连通分量 */
    int getCount() {
        return count;
    }

private:
    /*返回某个节点 x 的根节点 */
    int find(int x) {
        // 根节点的 parent[x] == x
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
};


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        int m = board.size();
        int n = board[0].size();
        UF uf(m * n + 1);
        int dummy = m * n;
        // 将⾸列和末列的 O 与 dummy 连通
        for (int i = 0; i < m; i++) {
            if (board[i][0] == '0') {
                uf.connet(i * n, dummy);
            }
            if (board[i][n - 1] == '0') {
                uf.connet(i * n + n - 1, dummy);
            }
        }
        // 将⾸⾏和末⾏的 O 与 dummy
        for (int j = 0; j < n; j++) {
            if (board[0][j] == '0') {
                uf.connet(j, dummy);
            }
            if (board[m - 1][j] == '0') {
                uf.connet(n * (m - 1) + j, dummy);
            }
        }
        // ⽅向数组 d 是上下左右搜索的常⽤⼿法
        int d[][2] = { {1,0}, {0,1}, {0,-1}, {-1,0} };
        for (int i = 1; i < m-1; i++) {
            for (int j = 1; j < n-1; j++) {
                if (board[i][j] == '0') {
                    // 将此 O 与上下左右的 O 连通
                    for (int k = 0; k < 4; k++) {
                        int x = i + d[k][0];
                        int y = j + d[k][1];
                        if (board[x][y] == '0') {
                            uf.connet(x * n + y, i * n + j);
                        }
                    }
                }
            }
        }

        // 所有不和 dummy 连通的 O， 都要被替换
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (!uf.connected(dummy, i * n + j)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};


int main()
{

}

