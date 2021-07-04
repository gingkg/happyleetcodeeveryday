/*
93. ��ԭIP��ַ
����һ��ֻ�������ֵ��ַ�������ԭ�����������п��ܵ� IP ��ַ��ʽ��

��Ч�� IP ��ַ�������ĸ�������ÿ������λ�� 0 �� 255 ֮����ɣ�������֮���� '.' �ָ���

ʾ��:
����: "25525511135"
���: ["255.255.11.135", "255.255.111.35"]

ִ�н����
ͨ��
ִ����ʱ��4 ms
�ڴ����ģ�6.8 MB
*/


#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

class Solution {
public:
    vector<string> vec;
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        string cur = s;
        if ((n < 4) || (n > 12)){
            return vec;
        }
        if (n == 4) {
            cur.insert(1, ".");
            cur.insert(2+1, ".");
            cur.insert(3+2, ".");
            vec.push_back(cur);
            return vec;
        }
        if (n == 12) {
            string part1 = cur.substr(0, 3);
            string part2 = cur.substr(3, 3);
            string part3 = cur.substr(6, 3);
            string part4 = cur.substr(9, 3);
            if (vaild(0, 2, s) && vaild(3, 5, s) && vaild(6, 8, s) && vaild(9, 11, s)) {
                vec.push_back(part1 + "." + part2 + "." + part3 + "." + part4);
            }
            return vec;
        }
        helper(n, 0, -1, cur, s);
        return vec;
    }

    
    void helper(int n, int pointnum, int lastpoint, string& cur, string& s) {
        if (pointnum == 3) {
            if (vaild(lastpoint + 1, n - 1, s)) {
                vec.push_back(cur);
            }
        }

        for (int i = lastpoint + 1; i < n - 1; i++) {
            if (vaild(lastpoint + 1, i, s)) {
                cur.insert(cur.begin() + i + pointnum + 1, '.');
                helper(n, pointnum + 1, i, cur, s);
                cur.erase(pointnum + i + 1, 1);
            }
        }
        return;
    }


    bool vaild(int left, int right, string& s) {
        if (((right - left) > 2) || ((right - left) > 0 and s[left] == '0')) return false;
        int sum = 0;
        for (int i = left; i <= right; i++) {
            sum = sum * 10 + (s[i] - '0');
            if (sum > 255) return false;
        }
        return true;
    }

};


int main()
{
    Solution solve;
    string s = "1212211112";
    vector<string> vec;
    vec = solve.restoreIpAddresses(s);

    vector<string>::iterator v = vec.begin();
    while (v != vec.end()) {
        cout << "value of v = " << *v << endl;
        v++;
    }
    return 0;
}
