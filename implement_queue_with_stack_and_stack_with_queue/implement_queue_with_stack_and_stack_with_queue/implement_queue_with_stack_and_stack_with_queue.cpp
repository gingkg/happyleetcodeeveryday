// implement_queue_with_stack_and_stack_with_queue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "MyQueue.h"
#include "MyStack.h"
using namespace std;

int main()
{
    cout << "Hello World!\n";
    MyStack<int> K;
    for (int i = 0; i < 10; i++) {
        K.push(i);
    }
    K.pop();
    K.pop();
    while (!K.empty()) {
        cout << K.top() << " ";
        K.pop();
    }
    cout << endl;
}

