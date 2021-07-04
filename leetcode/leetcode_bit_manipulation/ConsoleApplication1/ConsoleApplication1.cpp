// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
// ⼏个有趣的位操作

#include <iostream>
#include <cmath>
using namespace std;


void test1(bool open = true) {
    cout << "-----------------------------------" << endl;
    // 利⽤或操作 | 和空格将英⽂字符转换为⼩写
    cout << char(('a' | ' ')) << endl;
    cout << char(('A' | ' ')) << endl;

    // 利⽤与操作& 和下划线将英⽂字符转换为⼤写
    cout << char(('a' & '_')) << endl;
    cout << char(('A' & '_')) << endl;

    // 利⽤异或操作 ^ 和空格进⾏英⽂字符⼤⼩写互换
    cout << char(('a' ^ ' ')) << endl;
    cout << char(('A' ^ ' ')) << endl;
}


void test2(bool open = true) {
    cout << "-----------------------------------" << endl;
    // 判断两个数是否异号
    int x = -1, y = 2;
    if ((x ^ y) < 0) {
        cout << "两个数异号" << endl;
    }
    else {
        cout << "两个数同号" << endl;
    }
}


int main()
{
    test1();
    test2();
}

