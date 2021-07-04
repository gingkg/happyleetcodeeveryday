// 2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


template<typename T>
class TwoSum {
private:
    unordered_map<T, int> freq;

public:
    // 向数据结构中添加⼀个数 number
    void add(T number) {
        // 记录 number 出现的次数
        if (freq.count(number)) {
            freq.at(number) = freq.at(number) + 1;
        }
        else {
            freq.emplace(number, 1);
        }
    }

    // 寻找当前数据结构中是否存在两个数的和为 value
    bool find(T value) {
        typename unordered_map<T, int>::iterator iter;
        for (iter = freq.begin(); iter != freq.end(); iter++) {
            T other = value - iter->first;
            if (other == iter->first && iter->second > 1) {
                return true;
            }
            if (other != iter->first && freq.count(other)) {
                return true;
            }
        }
        return false;
    }
};



int main()
{
    cout << "Hello World!\n";
    cout << "2\n";
    TwoSum<int> twosum;
    twosum.add(3);
    twosum.add(3);
    twosum.add(2);
    twosum.add(5);
    if (twosum.find(6)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

}

