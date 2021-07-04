// Priority_Queue_with_Binary_Heap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "MaxPQ.h"
#include <iostream>
using namespace std;


int main()
{
    cout << "Hello World!\n";

    MaxPQ<int> PQ(50);
    for (int i = 1; i <= 25; i++) {
        PQ.insert(i);
    }

    cout << "容量:" << PQ.capacity() << endl;
    cout << "大小:" << PQ.size() << endl;
    PQ.print();

    cout << PQ.delMax() << endl; 
    cout << "容量:" << PQ.capacity() << endl;
    cout << "大小:" << PQ.size() << endl;
    PQ.print();

    //PQ.insert(778);
    for (int i = 1; i <= 29; i++) {
        PQ.insert(i);
    }
    cout << "容量:" << PQ.capacity() << endl;
    cout << "大小:" << PQ.size() << endl;
    PQ.print();

  



}

