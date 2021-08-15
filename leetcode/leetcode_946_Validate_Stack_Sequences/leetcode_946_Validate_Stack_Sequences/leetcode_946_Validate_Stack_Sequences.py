"""
给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true；否则，返回 false 。

示例 1：

输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
示例 2：

输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
输出：false
解释：1 不能在 2 之前弹出。
 

提示：

0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed 是 popped 的排列。
通过次数24,961提交次数40,308

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-stack-sequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

from typing import List
from collections import deque


class Solution:
    def trackback(self, pushed, popped, i, j, m, n, S):
        if i == m and j == n:
            return True

        # 入栈
        if i < n:
            S.append(pushed[i])
            if self.trackback(pushed, popped, i+1, j, m, n, S):
                return True
            S.pop()

        # 出栈
        if j < n and S:
            temp = S.pop()
            if temp != popped[j]:
                S.append(temp)
                return False
            if self.trackback(pushed, popped, i, j+1, m, n, S):
                return True
            S.append(temp)

        return False

    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        m = len(pushed)
        n = len(popped)
        S = deque()
        return self.trackback(pushed, popped, 0, 0, m, n, S)


if __name__ == "__main__":
    pushed = [1,2,3,4,5]
    popped = [4,5,3,2,1]
    S = Solution()
    if S.validateStackSequences(pushed, popped):
        print("true")
    else:
        print("fasle")

