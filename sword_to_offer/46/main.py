"""
剑指 Offer 46. 把数字翻译成字符串
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"

提示：

0 <= num < 231
"""


class Solution:
    def __init__(self):
        self.index = {i: chr(97+i) for i in range(26)}
        self.res = 0

    def trackback(self, num, n, i):
        if i == n:
            self.res = self.res + 1
            return

        # 选择
        # 当一个数字处理
        self.trackback(num, n, i+1)

        # 当两个数字处理
        if num[i] != '0' and i+1 < n:
            temp = int(num[i:i+2])
            if temp < 26:
                self.trackback(num, n, i + 2)

        return

    def translateNum(self, num: int) -> int:
        num = str(num)
        n = len(num)
        self.trackback(num, n, 0)
        return self.res


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    S = Solution()
    num = 506
    print(S.translateNum(num))

