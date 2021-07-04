/*
647. 回文子串
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。



示例 1：

输入："abc"
输出：3
解释：三个回文子串: "a", "b", "c"
示例 2：

输入："aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"


提示：

输入的字符串长度不会超过 1000 。

*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<string> res;
    int countSubstrings(string s) {
        int num = s.size();
        for (int i = 0; i < num; i++) res.push_back(s.substr(i,1));
        for (int i = 2; i <= s.size(); i++) {
            for (int j = 0; j <= s.size() - i; j++) {
                string src = s.substr(j, i);
                string des = src;
                reverse(des.begin(), des.end());
                if (src == des) {
                    num++;
                    res.push_back(src);
                }
            }
        }
        return num;
    }
};


// 中心拓展法
class Solution1 {
public:
    vector<string> res;
    int countSubstrings(string s) {
        int num = s.size();
        for (int i = 0; i < num; i++) res.push_back(s.substr(i, 1));
        //奇数
        for (int i = 1; i < int(s.size()) - 1; i++) {
            cout << "12345" << endl;
            int l = 1;
            while (i-l >= 0 && i+l<=s.size()) {
                if (s[i - l] == s[i + l]) {
                    num++;
                    res.push_back(s.substr(i - l, 2*l+1));
                    l++;
                }
                else {
                    break;
                }
            }
        }

        // 偶数
        for (int i = 0; i <= int(s.size()) - 2; i++) {
            cout << "123degtr45" << endl;
            int l = 0;
            while (i - l >= 0 && i +1+ l <= s.size()) {
                if (s[i - l] == s[i +1+ l]) {
                    num++;
                    res.push_back(s.substr(i - l, 2 * l + 2));
                    l++;
                }
                else {
                    break;
                }
            }
        }
        return num;
    }
};


//Manacher 算法(马拉车算法)
class Solution2 {
public:
    //vector<string> res;
    int countSubstrings(string s) {
        // 处理字符串
        int L = s.size();
        for (int i = 0; i <= L; i++) {
            s.insert(2*i, "#");
        }
        s.insert(0, "!");
        s.insert(s.size(), "*");

        auto f = vector<int>(s.size());
        int iMax = 0, rMax = 0, ans = 0;
        for (int i = 1; i < s.size(); i++) {
            f[i] = (i < rMax) ? min(rMax - i + 1, f[2 * iMax - i]) : 1;
            while (s[i + f[i]] == s[i - f[i]]) ++f[i];
            if (i + f[i] - 1 > rMax) {
                iMax = i;
                rMax = i + f[i] - 1;
            }
            ans += f[i] / 2;
        }
        return ans;
    }
};









int main()
{
    cout << "Hello World!\n";
    Solution2 S;
    string s = "abc";
    cout << S.countSubstrings(s) << endl;
    /*
    vector<string> res = S.res;
    vector<string>::iterator str;
    for (str = res.begin(); str != res.end(); str++) {
        cout << *str << endl;
    }*/

}
