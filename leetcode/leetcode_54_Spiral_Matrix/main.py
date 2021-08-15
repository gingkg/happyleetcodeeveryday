"""
54. 螺旋矩阵
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]

提示：
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

"""
from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        if m == 0:
            return []
        n = len(matrix[0])

        top = 0
        bottom = m-1
        left = 0
        right = n-1

        res = []

        while bottom >= top and right >= left:
            for i in range(left, right+1):
                res.append(matrix[top][i])
            for j in range(top+1, bottom+1):
                res.append(matrix[j][right])
            if bottom > top:
                for i in range(right-1,left-1,-1):
                    res.append(matrix[bottom][i])
            if right > left:
                for j in range(bottom-1, top, -1):
                    res.append(matrix[j][left])

            top = top + 1
            bottom = bottom - 1
            left = left + 1
            right = right - 1

        return res


if __name__ == '__main__':
    S = Solution()
    matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print(S.spiralOrder(matrix))

