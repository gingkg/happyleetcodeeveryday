"""
233. 数字 1 的个数
给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。

 

示例 1：

输入：n = 13
输出：6
示例 2：

输入：n = 0
输出：0
 

提示：

0 <= n <= 2 * 109
"""


class Solution:
    def countDigitOne(self, n: int) -> int:
        res = 0
        i = 1
        while i <= n:
            divider = i * 10
            res = res + (int(n/divider))*i + min(max(n%divider-i+1,0),i)
            i = i *10

        return res
            



