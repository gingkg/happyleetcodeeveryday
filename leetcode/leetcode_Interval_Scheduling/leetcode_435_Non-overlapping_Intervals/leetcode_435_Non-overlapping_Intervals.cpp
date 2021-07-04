// leetcode_435_Non-overlapping_Intervals.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
435. 无重叠区间
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
示例 1:

输入: [ [1,2], [2,3], [3,4], [1,3] ]

输出: 1

解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:

输入: [ [1,2], [1,2], [1,2] ]

输出: 2

解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
示例 3:

输入: [ [1,2], [2,3] ]

输出: 0

解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
*/




#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct myclass {
        bool operator() (vector<int> a, vector<int> b) { return (a[1] < b[1]); }
    } myobject;


    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //sort(intervals.begin(), intervals.end(), myobject);
        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
            return u[1] < v[1];
            });
        int N = intervals.size();
        int ans = 0;
        vector<int> temp = intervals[0];
        for (int i = 1; i < N; i++) {
            if (intervals[i][0] < temp[1]) {
                ans++;
            }
            else {
                temp = intervals[i];
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> intervals = { {1,2}, {2,3}, {3,4}, {1,3} };
    Solution S;
    cout << S.eraseOverlapIntervals(intervals) << endl;
    return -1;
}

//// sort algorithm example
//#include <iostream>     // std::cout
//#include <algorithm>    // std::sort
//#include <vector>       // std::vector
//
//bool myfunction(int i, int j) { return (i < j); }
//
//struct myclass {
//    bool operator() (int i, int j) { return (i < j); }
//} myobject;
//
//int main() {
//    int myints[] = { 32,71,12,45,26,80,53,33 };
//    std::vector<int> myvector(myints, myints + 8);               // 32 71 12 45 26 80 53 33
//
//    // using default comparison (operator <):
//    std::sort(myvector.begin(), myvector.begin() + 4);           //(12 32 45 71)26 80 53 33
//
//    // using function as comp
//    std::sort(myvector.begin() + 4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)
//
//    // using object as comp
//    std::sort(myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)
//
//    // print out content:
//    std::cout << "myvector contains:";
//    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
//        std::cout << ' ' << *it;
//    std::cout << '\n';
//
//    return 0;
//}
