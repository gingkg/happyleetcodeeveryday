// interviewer_10.01_Sorted_Merge_LCCI.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
面试题 10.01. 合并排序的数组
给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。

初始化 A 和 B 的元素数量分别为 m 和 n。

示例:

输入:
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
说明:

A.length == n + m
*/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (B[n-j-1] >= A[m-i-1]) {
                A[m + n - i - j - 1] = B[n - j - 1];
                j++;
            }
            else {
                A[m + n - i - j - 1] = A[m - i - 1];
                i++;
            }
        }
        for (; j < n; j++) {
            A[m + n - i - j - 1] = B[n - j - 1];
        }
    }
};

int main()
{
    vector<int> A = { 1,2,3,0,0,0 };
    int m = 3;
    vector<int> B = { 2,5,6 };
    int n = 3;
    Solution S;
    S.merge(A, 3, B, 3);
    for (int a : A) {
        cout << a << " ";
    }
    cout << endl;
}
