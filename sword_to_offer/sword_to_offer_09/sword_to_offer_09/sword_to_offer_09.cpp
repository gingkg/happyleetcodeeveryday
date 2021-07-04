// sword_to_offer_09.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
剑指 Offer 09. 用两个栈实现队列
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )



示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用
*/
/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

#include <iostream>
#include <stack>
using namespace std;

class CQueue {
private:
    stack<int> s1, s2;

public:
    CQueue() {

    }

    void appendTail(int value) {
        s1.push(value);
    }

    int deleteHead() {
        if (!s2.empty()) {
            int temp = s2.top();
            s2.pop();
            return temp;
        }
        else {
            if (!s1.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
                int temp = s2.top();
                s2.pop();
                return temp;
            }
        }
        return -1;
    }
};

class Solution2 {
public:
    int compute(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return compute(n - 1) + compute(n - 2);
    }

    int fib(int n) {
        return (compute(n) % int(1e9 + 7));
    }
};



int main()
{
    Solution2 S;
    int n = 100;
    cout << S.fib(n) << endl;
}

