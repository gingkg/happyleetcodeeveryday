// interview_0810_Color_Fill_LCCI.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
面试题 08.10. 颜色填充
编写函数，实现许多图片编辑软件都支持的「颜色填充」功能。

待填充的图像用二维数组 image 表示，元素为初始颜色值。初始坐标点的行坐标为 sr 列坐标为 sc。需要填充的新颜色为 newColor 。

「周围区域」是指颜色相同且在上、下、左、右四个方向上存在相连情况的若干元素。

请用新颜色填充初始坐标点的周围区域，并返回填充后的图像。



示例：

输入：
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
输出：[[2,2,2],[2,2,0],[2,0,1]]
解释:
初始坐标点位于图像的正中间，坐标 (sr,sc)=(1,1) 。
初始坐标点周围区域上所有符合条件的像素点的颜色都被更改成 2 。
注意，右下角的像素没有更改为 2 ，因为它不属于初始坐标点的周围区域。


提示：

image 和 image[0] 的长度均在范围 [1, 50] 内。
初始坐标点 (sr,sc) 满足 0 <= sr < image.length 和 0 <= sc < image[0].length 。
image[i][j] 和 newColor 表示的颜色值在范围 [0, 65535] 内。
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void fill(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) {
        int m = image.size();
        int n = image[0].size();
        if (newColor == oldColor) {
            return;
        }
        if (0 <= sr && sr < m && 0 <= sc && sc < n && image[sr][sc] == oldColor) {
            image[sr][sc] = newColor;
        }
        else {
            return;
        }
        fill(image, sr + 1, sc, newColor, oldColor);
        fill(image, sr - 1, sc, newColor, oldColor);
        fill(image, sr, sc + 1, newColor, oldColor);
        fill(image, sr, sc - 1, newColor, oldColor);
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        fill(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};

int main()
{
    cout << "Hello World!\n";
    vector<vector<int>> image = { {0, 0, 0}, {0, 1, 1}};
    int sr = 1, sc = 1, newColor = 1;
    Solution S;
    vector<vector<int>> res = S.floodFill(image, sr, sc, newColor);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

}

