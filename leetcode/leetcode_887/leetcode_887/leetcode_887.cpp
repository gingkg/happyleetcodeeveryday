/*
887. 鸡蛋掉落
给你 k 枚相同的鸡蛋，并可以使用一栋从第 1 层到第 n 层共有 n 层楼的建筑。

已知存在楼层 f ，满足 0 <= f <= n ，任何从 高于 f 的楼层落下的鸡蛋都会碎，从 f 楼层或比它低的楼层落下的鸡蛋都不会破。

每次操作，你可以取一枚没有碎的鸡蛋并把它从任一楼层 x 扔下（满足 1 <= x <= n）。如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，则可以在之后的操作中 重复使用 这枚鸡蛋。

请你计算并返回要确定 f 确切的值 的 最小操作次数 是多少？


示例 1：

输入：k = 1, n = 2
输出：2
解释：
鸡蛋从 1 楼掉落。如果它碎了，肯定能得出 f = 0 。
否则，鸡蛋从 2 楼掉落。如果它碎了，肯定能得出 f = 1 。
如果它没碎，那么肯定能得出 f = 2 。
因此，在最坏的情况下我们需要移动 2 次以确定 f 是多少。
示例 2：

输入：k = 2, n = 6
输出：3
示例 3：

输入：k = 3, n = 14
输出：4


提示：

1 <= k <= 100
1 <= n <= 10^4
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    unordered_map<int, int> memo;

    int dp(int k, int n) {
        if (k == 1) return n;
        if (n == 0) return 0;
        if (memo.count(n * 100 + k)) return memo[n * 100 + k];
        int res = n;
        int lo = 1, hi = n;
        while (lo + 1 < hi) {
            int x = (lo + hi) / 2;
            int t1 = dp(k - 1, x - 1);
            int t2 = dp(k, n - x);
            if (t1 < t2) {
                lo = x;
            }
            else if (t1 > t2) {
                hi = x;
            }
            else {
                lo = hi = x;
            }
        }

        res = 1 + min(max(dp(k - 1, lo - 1), dp(k, n - lo)), max(dp(k - 1, hi - 1), dp(k, n - hi)));
        memo[n * 100 + k] = res;
        return res;
    }


    int superEggDrop(int k, int n) {
        return dp(k, n);
    }
};


int main()
{
    cout << "Hello World!\n";
    int k = 4, n = 5000;
    Solution S;
    cout << S.superEggDrop(k, n) << endl;
}


