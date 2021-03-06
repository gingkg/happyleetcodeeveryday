// leetcode_1122_Relative_Sort_Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
1122. 数组的相对排序
给你两个数组，arr1 和 arr2，

arr2 中的元素各不相同
arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。



示例：

输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
输出：[2,2,2,1,4,3,3,9,6,7,19]


提示：

1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2 中的元素 arr2[i] 各不相同
arr2 中的每个元素 arr2[i] 都出现在 arr1 中
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> count;
        vector<int> res;
        for (int arr : arr1) {
            count[arr] = count[arr] + 1;
        }
        for (int i : arr2) {
            for (int j = 0; j < count[i]; j++) {
                res.push_back(i);
            }
            count.erase(i);
        }
        for (auto iter = count.begin(); iter != count.end(); iter++) {
            for (int i = 0; i < iter->second; i++) {
                res.push_back(iter->first);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
    vector<int> arr2 = { 2,1,4,3,9,6 };
    Solution S;
    vector<int> res = S.relativeSortArray(arr1, arr2);
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
}

