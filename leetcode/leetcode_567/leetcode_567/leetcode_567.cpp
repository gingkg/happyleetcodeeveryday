/*
567. 字符串的排列
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例 1：
输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").

示例 2：
输入: s1= "ab" s2 = "eidboaoo"
输出: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (char c : s1) need[c]++;
        int left = 0, right = 0;
        int valid = 0;
        while(right < s2.size()){
            char c = s2[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            while (right - left >= s1.size()) {
                if (valid == need.size()) {
                    return true;
                }
                char d = s2[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
            
        }
        return false;
    }
};


class SolutionViolence {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (char c : s1) need[c]++;
        int left = 0, len = s1.size();
        for (; left + len <= s2.size(); left++) {
            bool valid = true;
            window.clear();
            for (char c : s2.substr(left, len)) window[c]++;
            auto iter = window.begin();//auto自动识别为迭代器类型unordered_map<int,string>::iterator
            while (iter != window.end())
            {
                if (!(need.count(iter->first) && need[iter->first] == window[iter->first])) {
                    valid = false;
                    break;
                }
                ++iter;
            }
            if (valid) {
                return true;
            }
        }
        return false;
    }
};






int main()
{
    std::cout << "Hello World!\n";
    // string s1 = "hello", s2 = "ooolleoooleh";
    
    string s1 = "adc", s2 = "dcda";
    Solution S;
    if (S.checkInclusion(s1, s2)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    /*
    unordered_map<char, int> need = { {'a', 2}, {'b', 3} };
    cout << need['c'] << endl;
    cout << need.size() << endl;
    */

}

