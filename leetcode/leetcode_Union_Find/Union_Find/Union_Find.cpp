// Union_Find.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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




int main()
{
    std::cout << "Hello World!\n";
}

