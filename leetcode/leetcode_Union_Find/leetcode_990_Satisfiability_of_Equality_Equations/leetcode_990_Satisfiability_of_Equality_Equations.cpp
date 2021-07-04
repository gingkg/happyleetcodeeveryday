// leetcode_990_Satisfiability_of_Equality_Equations.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
990. 等式方程的可满足性
给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。

只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。



示例 1：

输入：["a==b","b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。
示例 2：

输入：["b==a","a==b"]
输出：true
解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。
示例 3：

输入：["a==b","b==c","a==c"]
输出：true
示例 4：

输入：["a==b","b!=c","c==a"]
输出：false
示例 5：

输入：["c==c","b==d","x!=z"]
输出：true


提示：

1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] 和 equations[i][3] 是小写字母
equations[i][1] 要么是 '='，要么是 '!'
equations[i][2] 是 '='
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
    bool equationsPossible(vector<string>& equations) {
        UF uf(26);
        for (const auto& equation : equations) {
            if (equation[1] == '=') {
                uf.connet(equation[0] - 'a', equation[3] - 'a');
            }
        }

        for (const auto& equation : equations) {
            if (equation[1] == '!') {
                if (uf.connected(equation[0] - 'a', equation[3] - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    cout << "Hello World!\n";
    Solution S;
    vector<string> equations = { "a==b","b!=a" };
    cout << S.equationsPossible(equations) << endl;
}



