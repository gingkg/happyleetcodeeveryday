/*
1751. 最多可以参加的会议数目 II

给你一个 events 数组，其中 events[i] = [startDayi, endDayi, valuei] ，表示第 i 个会议在 startDayi 天开始，
第 endDayi 天结束，如果你参加这个会议，你能得到价值 valuei 。同时给你一个整数 k 表示你能参加的最多会议数目。

你同一时间只能参加一个会议。如果你选择参加某个会议，那么你必须 完整 地参加完这个会议。会议结束日期是包含在会议内的，
也就是说你不能同时参加一个开始日期与另一个结束日期相同的两个会议。

请你返回能得到的会议价值 最大和 。

输入：events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
输出：7
解释：选择绿色的活动会议 0 和 1，得到总价值和为 4 + 3 = 7 。

66 / 66 个通过测试用例
状态：通过
执行用时: 544 ms
内存消耗: 61.8 MB

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


class Solution {
public:
    static bool cmpUp(vector<int>& a, vector<int>& b) {
        if (a[1] < b[1]) {
            return true;
        }
        else {
            return false;
        }
    }

    int maxValue(vector<vector<int>>& events, int k) {
        // 对events排序
        sort(events.begin(), events.end(), cmpUp);
        vector<vector<int>>::iterator it;
        for (it = events.begin(); it != events.end(); it++) {
            for (unsigned int i = 0; i < (*it).size(); i++) {
                cout << (*it)[i] << " ";
            }
            cout << endl;
        }

        // 动态规划
        // 
        unsigned int numEvents = events.size();
        vector<vector<int>> dp(numEvents, vector<int>(k, 0));
        dp[0] = vector<int>(k, events[0][2]);
        int maxValue = events[0][2];
        for (unsigned int i = 1; i < numEvents; i++) {
            if (events[i][2] > maxValue) {
                maxValue = events[i][2];
            }
            dp[i][0] = maxValue;
        }
        for (unsigned int i = 1; i < numEvents; i++) {
            for (unsigned int j = 1; j < k; j++) {
                int L = -1;
                // 参加第i场会议, 寻找结束时间小于i开始时间的会议
                int left = 0;
                int right = i - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (events[mid][1] < events[i][0]) {
                        left = mid + 1;
                        L = mid;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                if (L >= 0 ) {
                    dp[i][j] = max(dp[i - 1][j], dp[L][j-1] + events[i][2]);
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], events[i][2]);
                }
            }
        }

        cout << "======================" << endl;

        for (it = dp.begin(); it != dp.end(); it++) {
            for (unsigned int i = 0; i < (*it).size(); i++) {
                cout << (*it)[i] << " ";
            }
            cout << endl;
        }


        return dp[numEvents-1][k-1];
    }
};


int main()
{
    Solution S;
    vector<vector<int>> events = { {1,3,4}, {2,4,1}, {1,1,4}, {3,5,1}, {2,5,5} };
    int k = 3;
    cout << S.maxValue(events, k) << endl;

}


