// leetcode_1116_Print_Zero_Even_Odd.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
1116. 打印零与奇偶数
假设有这么一个类：

class ZeroEvenOdd {
  public ZeroEvenOdd(int n) { ... }      // 构造函数
  public void zero(printNumber) { ... }  // 仅打印出 0
  public void even(printNumber) { ... }  // 仅打印出 偶数
  public void odd(printNumber) { ... }   // 仅打印出 奇数
}
相同的一个 ZeroEvenOdd 类实例将会传递给三个不同的线程：

线程 A 将调用 zero()，它只输出 0 。
线程 B 将调用 even()，它只输出偶数。
线程 C 将调用 odd()，它只输出奇数。
每个线程都有一个 printNumber 方法来输出一个整数。请修改给出的代码以输出整数序列 010203040506... ，其中序列的长度必须为 2n。



示例 1：

输入：n = 2
输出："0102"
说明：三条线程异步执行，其中一个调用 zero()，另一个线程调用 even()，最后一个线程调用odd()。正确的输出为 "0102"。
示例 2：

输入：n = 5
输出："0102030405"
*/


#include <iostream>
#include <mutex>
#include <vector>
#include <thread>
#include <condition_variable>
using namespace std;


class ZeroEvenOdd {
private:
    int n;
    mutex m;
    vector<bool> flag = { false, false, false };
    condition_variable c0, c1, c2;
    int i = 1;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero() {
        unique_lock<mutex> L0(m);
        cout << "0线程开始......" << endl;
        while (i <= n)
        {
            if (!flag[0]) {
                cout << 0 << endl;
                flag[0] = true;
                //flag[1] = false;
                //flag[2] = false;
            }
            if (i % 2 == 1) {
                c1.notify_one();
            }
            else {
                c2.notify_one();
            }
            if (i == n) break;
            c0.wait(L0);
        }
        cout << "0线程结束" << endl;
    }

    void even() {
        unique_lock<mutex> L2(m);
        cout << "偶数线程开始......" << endl;
        while (i <= n)
        {
            if (i % 2 == 0 && flag[0]) {
                cout << i << endl;
                i++;
                flag[0] = false;
                // flag[2] = true;
            }
            c0.notify_one();
            if (i >= n) break;
            c2.wait(L2);
        }
        cout << "偶数线程结束" << endl;
    }

    void odd() {
        unique_lock<mutex> L1(m);
        cout << "奇数线程开始......" << endl;
        while (i <= n)
        {
            if (i % 2 == 1 && flag[0])
            {
                cout << i << endl;
                i++;
                flag[0] = false;
                // flag[1] = true;
            }
            c0.notify_one();
            if (i >= n) break;
            c1.wait(L1);
        }
        cout << "奇数线程结束" << endl;
    }
};

int main()
{
    int n = 3;
    ZeroEvenOdd zeo(n);

    cout << "主线程开始......" << endl;
    thread p0(&ZeroEvenOdd::zero, &zeo);
    thread p1(&ZeroEvenOdd::odd, &zeo);
    thread p2(&ZeroEvenOdd::even, &zeo);

    p0.join();
    p1.join();
    p2.join();

    cout << "主线程结束。" << endl;

}

