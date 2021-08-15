// leetcode_223_Rectangle_Area.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
223. 矩形面积
给你 二维 平面上两个 由直线构成的 矩形，请你计算并返回两个矩形覆盖的总面积。

每个矩形由其 左下 顶点和 右上 顶点坐标表示：

第一个矩形由其左下顶点 (ax1, ay1) 和右上顶点 (ax2, ay2) 定义。
第二个矩形由其左下顶点 (bx1, by1) 和右上顶点 (bx2, by2) 定义。


示例 1：

Rectangle Area
输入：ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
输出：45
示例 2：

输入：ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
输出：16


提示：

-104 <= ax1, ay1, ax2, ay2, bx1, by1, bx2, by2 <= 104
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int chonghe(int ax1, int ax2, int bx1, int bx2) {
        if (ax2 <= bx1) {
            return 0;
        }
        else if (ax1 <= bx1 && bx1 < ax2 && ax2 <= bx2) {
            return ax2 - bx1;
        }
        else if (ax1 <= bx1 && bx2 <= ax2) {
            return bx2 - bx1;
        }
        else if (bx1 <= ax1 && ax2 <= bx2) {
            return ax2 - ax1;
        }
        else if (bx1 <= ax1 && ax1 < bx2 && bx2 < ax2) {
            return bx2 - ax1;
        }
        else {
            return 0;
        }
    }


    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // 算重合面积
        // x 差值
        int x = chonghe(ax1, ax2, bx1, bx2);
        int y = chonghe(ay1, ay2, by1, by2);

        return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - x * y;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

