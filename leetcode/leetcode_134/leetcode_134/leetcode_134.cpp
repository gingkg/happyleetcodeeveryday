/*
134. 加油站
在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。 
如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。

说明:
如果题目有解，该答案即为唯一答案。
输入数组均为非空数组，且长度相同。
输入数组中的元素均为非负数。

示例 1:
输入:
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]
输出: 3

解释:
从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
因此，3 可为起始索引。

示例 2:
输入:
gas  = [2,3,4]
cost = [3,4,3]
输出: -1
解释:
你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
因此，无论怎样，你都不可能绕环路行驶一周。


*/

#include <iostream>
#include <vector>
using namespace std;


// 暴力解
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = 0, n = 0, i = 0, flag = 1, num = 0;
        N = gas.size();
        int gasNum = 0, costNum = 0;
        for (int j = 0; j < N; j++) {
            gasNum = gasNum + gas[j];
            costNum = costNum + cost[j];
        }
        if (gasNum < costNum) {
            return -1;
        }
        while (n < N) {
            num = 0;
            flag = 1;
            i = n;
            for (int j = 0; j < N; j++) {
                num = num + gas[i] - cost[i];
                if (num < 0) {
                    flag = 0;
                    break;
                }
                i++;
                if (i >= N) {
                    i = 0;
                }
                
            }
            if (flag == 1) {
                return n;
            }
            n++; 
        }
        return -1;
    }
};


// 贪心算法（方法一）
class GreedySolution1 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();
        int curSum = 0;
        int min = curSum;
        for (int i; i < N; i++) {
            curSum = curSum + gas[i] - cost[i];
            if (curSum < min) {
                min = curSum;
            }
        }
        if (curSum < 0) {
            return -1;
        }
        if (min >= 0) {
            return 0;
        }
        for (int i = N - 1; i >= 0; i--) {
            min = min + gas[i] - cost[i];
            if (min >= 0) {
                return i;
            }
        }
        return -1;
    }
};

//贪心算法（方法一）
class GreedySolution2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (curSum < 0) {   // 当前累加rest[i]和 curSum一旦小于0
                start = i + 1;  // 起始位置更新为i+1
                curSum = 0;     // curSum从0开始
            }
        }
        if (totalSum < 0) return -1; // 说明怎么走都不可能跑一圈了
        return start;
    }
};


int main()
{
    vector<int> gas = { 1,2,3,4,5 };
    vector<int> cost = { 3,4,5,1,2 };
    Solution S;
    int num = -1;

    num = S.canCompleteCircuit(gas, cost);
    if (num >= 0) {
        cout << "可以绕环路行驶一周，出发时加油站的编号为：" << num << endl;
    }
    else {
        cout << "不可以绕环路行驶一周。" << endl;
    }
  
    return 0;
}