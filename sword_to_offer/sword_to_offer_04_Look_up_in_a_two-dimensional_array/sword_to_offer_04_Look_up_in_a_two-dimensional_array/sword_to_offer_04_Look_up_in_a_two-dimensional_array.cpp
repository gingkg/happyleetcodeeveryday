// sword_to_offer_04_Look_up_in_a_two-dimensional_array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
剑指 Offer 04. 二维数组中的查找
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。



限制：

0 <= n <= 1000

0 <= m <= 1000
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool backtrack(vector<vector<int>>& matrix, int target, int i, int j, vector<vector<bool>>& flag) {
        int n = matrix.size(), m = matrix[0].size();
        if (i >= n || j >= m) return false;
        if (flag[i][j]) { 
            return false;
        }
        else {
            flag[i][j] = true;
        }
        if (matrix[i][j] == target) return true;
        if (matrix[i][j] > target) return false;
        if (backtrack(matrix, target, i + 1, j, flag)) return true;
        if (backtrack(matrix, target, i, j+1, flag)) return true;
        return false;
    }

    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0) return false;
        int n = matrix.size(), m = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[n - 1][m - 1]) return false;
        vector<vector<bool>> flag(n, vector<bool>(m, false));

        return backtrack(matrix, target, 0, 0, flag);
    }
};


class Solution2 {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0) return false;
        int n = matrix.size(), m = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[n - 1][m - 1]) return false;

        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] > target) {
                j--;
            }
            else {
                i++;
            }
        }
        
        return false;
    }
};



int main()
{
    Solution2 S;
    vector<vector<int>> matrix = {
                                  {1,   4,  7, 11, 15},
                                  {2,   5,  8, 12, 19},
                                  {3,   6,  9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}
                                  };
    int target = 20;
    if (S.findNumberIn2DArray(matrix, target)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}

