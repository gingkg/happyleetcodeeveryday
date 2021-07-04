/*
3. 无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度
示例 1:

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
示例 4:

输入: s = ""
输出: 0
 

提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成

987 / 987 个通过测试用例
状态：通过
执行用时: 24 ms
内存消耗: 8 MB

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int output = 0;
        int left = 0, right = 0;
        while (right < s.size()) {
            /*
            if (s.size() - left <= output) {
                break;
            }*/
            char c = s[right];
            right++;
            window[c]++;
            if (window[c] <= 1 && right-left > output) {
                output = right - left;
            }
            while (window[c] > 1) {
                char d = s[left];
                left++;
                window[d]--;
            }
        }
        return output;
    }
};


//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        unordered_map<char, int> window;
//        int left = 0, right = 0;
//        int res = 0; // 记录结果
//        while (right < s.size()) {
//            char c = s[right];
//            right++;
//            // 进行窗口内数据的一系列更新
//            window[c]++;
//            // 判断左侧窗口是否要收缩
//            while (window[c] > 1) {
//                char d = s[left];
//                left++;
//                // 进行窗口内数据的一系列更新
//                window[d]--;
//            }
//            // 在这里更新答案
//            res = max(res, right - left);
//        }
//        return res;
//    }
//};


int main()
{
    std::cout << "Hello World!\n";
    Solution S;
    string s = "";
    cout << S.lengthOfLongestSubstring(s) << endl;
}


