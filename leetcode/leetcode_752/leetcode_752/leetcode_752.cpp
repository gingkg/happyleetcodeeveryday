// leetcode_752.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

// BFS
class Solution {
public:
    vector<string> adj(string s) {
        vector<string> vecAdj;
        for (unsigned int i = 0; i < s.size(); i++) {
            string s_ = s;
            int a = s[i] - '0';
            int b;

            b = a + 1;
            if (b > 9) {
                b = 0;
            }
            s_[i] = b + '0';
            vecAdj.push_back(s_);

            b = a - 1;
            if (b < 0) {
                b = 9;
            }
            s_[i] = b + '0';
            vecAdj.push_back(s_);
        }
        return vecAdj;
    }

    // 将 s[j] 向上拨动⼀次
    string plusOne(string s, int j) {
        int a = (s[j] - '0' + 1 + 10)%10;
        s[j] = a + '0';
        return s;
    }

    // 将 s[j] 向下拨动⼀次
    string minuOne(string s, int j) {
        int a = (s[j] - '0' - 1 + 10)%10;
        s[j] = a + '0';
        return s;
    }


    int openLock(vector<string>& deadends, string target) {
        queue<string> Q;
        //set<string> visited;
        unordered_set<string> visited;

        string start = "0000";
        Q.push(start);
        visited.insert(deadends.begin(), deadends.end());

        if (find(visited.begin(), visited.end(), start) != visited.end()) {
            return -1;
        }
        int steps = 0;

        visited.insert(start);

        while (!Q.empty()) {
            int sz = Q.size();
            for (int i = 0; i < sz; i++) {
                string cur = Q.front();
                Q.pop();

                /* 划重点： 这⾥判断是否到达终点 */
                if (cur == target) {
                    return steps;
                }

                /* 将 cur 的相邻节点加⼊队列 */
                for (unsigned int j = 0; j < 4; j++) {
                    string up = plusOne(cur, j);
                    if (!visited.count(up)) {
                        Q.push(up);
                        visited.emplace(up);
                    }

                    string down = minuOne(cur, j);
                    if (!visited.count(down)) {
                        Q.push(down);
                        visited.emplace(down);
                    }
                }

                /*
                vector<string> curAdj = adj(cur);
                for (int j = 0; j < curAdj.size(); j++) {
                    if (!visited.count(curAdj[j])) {
                        Q.push(curAdj[j]);
                        visited.insert(curAdj[j]);
                    }

                }*/
            }
            steps++;
        }
        return -1;
    }

    int openLock_bothwayBFS(vector<string>& deadends, string target) {
        unordered_set<string> deads, visited, Q1, Q2;

        string start = "0000";
        Q1.emplace(start);
        Q2.emplace(target);
        visited.insert(deadends.begin(), deadends.end());
        //deads.insert(deadends.begin(), deadends.end());

        int steps = 0;

        unordered_set<string> temp;

        while (!Q1.empty() && !Q2.empty()) {
            temp.clear();
           
            for (string cur: Q1) {
                /* 划重点： 这⾥判断是否到达终点 */
                /*if (deads.count(cur)) {
                    continue;
                }*/

                if (Q2.count(cur)) {
                    return steps;
                }

                //visited.emplace(cur);

                /* 将 cur 的相邻节点加⼊队列 */
                for (unsigned int j = 0; j < 4; j++) {
                    string up = plusOne(cur, j);
                    if (!visited.count(up)) {
                        temp.emplace(up);
                        visited.emplace(cur);
                    }

                    string down = minuOne(cur, j);
                    if (!visited.count(down)) {
                        temp.emplace(down);
                        visited.emplace(cur);
                    }
                }
            }
            steps++;
            // temp 相当于 q1
            // 这⾥交换 q1 q2， 下⼀轮 while 就是扩散 q2
            Q1 = Q2;
            Q2 = temp;
        }
        return -1;
    }
};



int main()
{
    std::cout << "Hello World!\n";

    vector<string> D{ "8888" };
    string T = "0009";

    Solution S;
    cout << S.openLock_bothwayBFS(D, T) << endl;


}

