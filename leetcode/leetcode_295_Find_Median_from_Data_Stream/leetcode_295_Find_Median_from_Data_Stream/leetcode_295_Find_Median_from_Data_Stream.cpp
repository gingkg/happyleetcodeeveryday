// leetcode_295_Find_Median_from_Data_Stream.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
295. 数据流的中位数
中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例：

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2
进阶:

如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;



class MedianFinder {
public:
    priority_queue<int> lo;  // max heap
    priority_queue<int, vector<int>, greater<int>> hi;  // min heap

    MedianFinder() {
    }

    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();

        if (hi.size() > lo.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        return lo.size() > hi.size() ? lo.top() : (lo.top() + hi.top())*0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */



int main()
{
    std::cout << "Hello World!\n";
}

