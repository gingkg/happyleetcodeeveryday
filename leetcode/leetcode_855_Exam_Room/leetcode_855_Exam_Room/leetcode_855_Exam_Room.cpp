// leetcode_855_Exam_Room.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
855. 考场就座
在考场里，一排有 N 个座位，分别编号为 0, 1, 2, ..., N-1 。

当学生进入考场后，他必须坐在能够使他与离他最近的人之间的距离达到最大化的座位上。如果有多个这样的座位，他会坐在编号最小的座位上。(另外，如果考场里没有人，那么学生就坐在 0 号座位上。)

返回 ExamRoom(int N) 类，它有两个公开的函数：其中，函数 ExamRoom.seat() 会返回一个 int （整型数据），代表学生坐的位置；函数 ExamRoom.leave(int p) 代表坐在座位 p 上的学生现在离开了考场。每次调用 ExamRoom.leave(p) 时都保证有学生坐在座位 p 上。



示例：

输入：["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
输出：[null,0,9,4,2,null,5]
解释：
ExamRoom(10) -> null
seat() -> 0，没有人在考场里，那么学生坐在 0 号座位上。
seat() -> 9，学生最后坐在 9 号座位上。
seat() -> 4，学生最后坐在 4 号座位上。
seat() -> 2，学生最后坐在 2 号座位上。
leave(4) -> null
seat() -> 5，学生最后坐在 5 号座位上。


提示：

1 <= N <= 10^9
在所有的测试样例中 ExamRoom.seat() 和 ExamRoom.leave() 最多被调用 10^4 次。
保证在调用 ExamRoom.leave(p) 时有学生正坐在座位 p 上。
*/


#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int N;

class comp {
public:
    int distance(vector<int> intV) const {
        int x = intV[0];
        int y = intV[1];
        if (x == -1) return y;
        if (y == N) return N - 1 - x;
        // 中点和端点之间的⻓度
        return (y - x) / 2;
    }

    bool operator() (vector<int> a, vector<int> b) const {
        if (a[0] == b[0] && a[1] == b[1]) {
            return false;
        }
        else {
            int disA = distance(a);
            int disB = distance(b);
            if (disA == disB) {
                return a[0] > b[0];
                
            }
            else {
                return disA < disB;
            }
        }
    }
};




class ExamRoom {
private:
    map<int, vector<int>> startMap;
    map<int, vector<int>> endMap;
    set<vector<int>, comp> pq;

public:
    ExamRoom(int n) {
        N = n;
        addInterval({ -1, N });
    }

    int seat() {
        vector<int> longest = *(pq.rbegin());
        int x = longest[0], y = longest[1];
        int seat;
        if (x == -1) {
            seat = 0;
        }
        else if (y == N) {
            seat = N - 1;
        }
        else {
            seat = (y - x) / 2 + x;
        }

        // 将最⻓的线段分成两段
        vector<int> left = { x, seat };
        vector<int> right = { seat, y };
        removeInterval(longest);
        addInterval(left);
        addInterval(right);
        return seat;
    }

    void leave(int p) {
        if (startMap.count(p)) {
            // 将 p 左右的线段找出来
            vector<int> right = startMap.at(p);
            vector<int> left = endMap.at(p);
            // 合并两个线段成为⼀个线段
            vector<int> merged = { left[0], right[1] };
            removeInterval(left);
            removeInterval(right);
            addInterval(merged);
        }
    }

private:
    /*增加⼀个线段 */
    void addInterval(vector<int> intV) {
        pq.emplace(intV);
        startMap.emplace(intV[0], intV);
        endMap.emplace(intV[1], intV);
    }

    /*去除⼀个线段 */
    void removeInterval(vector<int> intV) {
        pq.erase(intV);
        startMap.erase(intV[0]);
        endMap.erase(intV[1]);
    }
};


/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */


int main()
{
    cout << "Hello World!\n";
    set<vector<int>, comp> test;
    test.emplace(vector<int> { 0, 1 });
    test.emplace(vector<int> { 1, 3 });


    auto iter = test.begin();
    for (; iter != test.end(); iter++) {
        cout << (*iter)[0] << " " << (*iter)[1] << endl;
    }

    cout << "##########################" << endl;
    ExamRoom* obj = new ExamRoom(100);
    for (int i = 0; i < 10; i++) {
        cout << obj->seat() << endl;
    }
    obj->leave(25);

    return -1;
}

