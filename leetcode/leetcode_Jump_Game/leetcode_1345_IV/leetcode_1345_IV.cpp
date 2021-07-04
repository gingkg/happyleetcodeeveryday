// leetcode_1345_IV.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
1345. 跳跃游戏 IV
给你一个整数数组 arr ，你一开始在数组的第一个元素处（下标为 0）。

每一步，你可以从下标 i 跳到下标：

i + 1 满足：i + 1 < arr.length
i - 1 满足：i - 1 >= 0
j 满足：arr[i] == arr[j] 且 i != j
请你返回到达数组最后一个元素的下标处所需的 最少操作次数 。

注意：任何时候你都不能跳到数组外面。



示例 1：

输入：arr = [100,-23,-23,404,100,23,23,23,3,404]
输出：3
解释：那你需要跳跃 3 次，下标依次为 0 --> 4 --> 3 --> 9 。下标 9 为数组的最后一个元素的下标。
示例 2：

输入：arr = [7]
输出：0
解释：一开始就在最后一个元素处，所以你不需要跳跃。
示例 3：

输入：arr = [7,6,9,6,9,6,9,7]
输出：1
解释：你可以直接从下标 0 处跳到下标 7 处，也就是数组的最后一个元素处。
示例 4：

输入：arr = [6,1,9]
输出：2
示例 5：

输入：arr = [11,22,7,7,7,7,7,7,7,22,13]
输出：3


提示：

1 <= arr.length <= 5 * 10^4
-10^8 <= arr[i] <= 10^8

执行结果： 通过
执行用时：192 ms, 在所有 C++ 提交中击败了79.55%的用户
内存消耗：59.6 MB, 在所有 C++ 提交中击败了85.23%的用户
*/



#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int target = arr[n - 1];
        // 使用哈希表记录相同元素的位置
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++) {
            if (0 < i && i < n - 1) {
                if (arr[i] == arr[i - 1] && arr[i] == arr[i + 1])
                    continue;
            }
            map[arr[i]].push_back(i);
        }
        /*
        for (int i = 0; i < n; i++) {
            map[arr[i]].push_back(i);
        }

        for (unordered_map<int, vector<int>>::iterator iter = map.begin(); iter != map.end(); iter++) {
            vector<int> curList = iter->second;
            vector<int> res;
            int left = 0, right = 1;
            while (right < curList.size()) {
                if (curList[right] - curList[left] == right - left) {
                    right++;
                }
                else {
                    res.push_back(curList[left]);
                    res.push_back(curList[right]);
                    left = right;
                }
            }
            if (right - 1 == left) {
                res.push_back(curList[left]);
            }
            else {
                res.push_back(curList[left]);
                res.push_back(curList[right-1]);
            }
            iter->second = res;
        }
        */

        for (unordered_map<int, vector<int>>::iterator iter = map.begin(); iter != map.end(); iter++) {
            cout << iter->first << ": ";
            for (const auto& x : iter->second) {
                cout << x << " ";
            }
            cout << endl;
        }

        
        // 双向bfs
        unordered_set<int> s1, s2, temp;
        vector<bool> visited(n, false);
        int steps = 0;
        s1.emplace(0);
        s2.emplace(n - 1);
        
        while (!s1.empty() && !s2.empty()) {
            // 哈希集合在遍历的过程中不能修改， ⽤ temp 存储扩散结果
            temp.clear();
            for (const auto& cur : s1) {
                if (s2.count(cur)) {
                    return steps;
                }
                visited[cur] = true;

                for (const auto& x : map[arr[cur]]) {
                    if (!visited[x]) {
                        temp.emplace(x);
                    }
                }

                if (cur + 1 < n && arr[cur] != arr[cur+1] && !visited[cur + 1]) {
                    temp.emplace(cur + 1);

                }
                if (cur - 1 >= 0 && arr[cur] != arr[cur - 1] && !visited[cur - 1]) {
                    temp.emplace(cur - 1);
                }
            }
            steps++;
            s1 = s2;
            s2 = temp;
        }
        return -1;
    }
};

int main()
{
    Solution S;
    vector<int> arr = { 7,7,7,7,7,7,7,3,4,6,6,6,6,1 };
    cout << S.minJumps(arr) << endl;
}

