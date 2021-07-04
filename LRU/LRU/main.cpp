// main.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <unordered_map>
#include "LRU.h"
using namespace std;

int main()
{
    LRUCache<int, int> lru(10);

    
    for (int i = 1,j = 1; i <= 15 && j <= 15; i++, j++) {
        cout << i << endl;
        lru.put(i, i+j);
    }
    lru.print();

    for (int i = 14; i > 10; i--) {
        cout << i << endl;
        lru.get(i);
    }
   lru.print();
    
    return 0;
}
