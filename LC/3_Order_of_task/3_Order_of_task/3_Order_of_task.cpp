// 3_Order_of_task.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Vertex
{
public:
    int val;
    vector<Vertex*> next;
    vector<Vertex*> last;

public:
    Vertex() {
        val = 0;
    }

    Vertex(int v) {
        val = v;
    }

public:
    void add_next(Vertex* p) {
        next.push_back(p);
    }

    void add_last(Vertex* p) {
        last.push_back(p);
    }

    int size_next() {
        return next.size();
    }

    int size_last() {
        return last.size();
    }
};



class Graph
{
private:
    int numVertexes;
    int numEdges;
    unordered_map<int, Vertex*> mapVertexes;

public:
    Graph() {
        numVertexes = 0;
        numEdges = 0;
    }

    Graph(int a, int b) {
        numVertexes = a;
        numEdges = b;
    }

public:
    void add(int v_p, int v_c) {
        // 检查顶点是否已经存在，不存在创建
        Vertex* parent = nullptr;
        Vertex* child = nullptr;
        if (mapVertexes.count(v_p)) {
            parent = mapVertexes[v_p];
        }
        else {
            parent = new Vertex(v_p);
            mapVertexes[v_p] = parent;
        }
        if (mapVertexes.count(v_c)) {
            child = mapVertexes[v_c];
        }
        else {
            child = new Vertex(v_c);
            mapVertexes[v_c] = child;
        }

        // 添加子节点
        parent->add_next(child);
        child->add_last(parent);
    }

    void addByVec(vector<int>& vec) {
        for (int i = 0; i < vec.size() - 1; i = i + 2) {
            add(vec[i], vec[i + 1]);
        }
    }

    void dfs(Vertex* root, unordered_set<int>& visited, vector<int>& res) {
        if (visited.count(root->val)) return;

        for (auto p : root->last) {
            if (!visited.count(p->val)) return;
        }

        // 需要的高优先级任务以全部完成
        visited.emplace(root->val);
        res.push_back(root->val);

        // 下一级任务
        for (auto p : root->next) {
            dfs(p, visited, res);
        }

        return;
    }

    vector<int> solve() {
        vector<int> res;
        unordered_set<int> visited;

        for (auto iter = mapVertexes.begin(); iter != mapVertexes.end(); iter++) {
            if (iter->second->size_last() == 0) {
                // 可以作为起点
                dfs(iter->second, visited, res);
            }
        }

        return res;
    }
};



int main()
{
    // 这两个值对本程序没有意义
    int numVertexes = 9;
    int numEdges = 9;

    vector<vector<int>> raw = {
        { 4, 1, 1, 2, 2, 3, 2, 7, 5, 6, 7, 6, 1, 5, 8, 5, 8, 9 },
        {1, 2, 2, 3, 4, 1, 1, 5} };


    for (int i = 0; i < raw.size(); i++) {
        Graph G(numVertexes, numEdges);
        G.addByVec(raw[i]);
        vector<int> res = G.solve();

        cout << "#" << i+1 << " ";
        for (int v : res) {
            cout << v << " ";
        }
        cout << endl;
    }
}


