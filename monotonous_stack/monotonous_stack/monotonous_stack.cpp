// monotonous_stack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;


//这就是单调队列解决问题的模板。 for 循环要从后往前扫描元素， 因为我们
//借助的是栈的结构， 倒着⼊栈， 其实是正着出栈。 while 循环是把两个“⾼
//个”元素之间的元素排除， 因为他们的存在没有意义， 前⾯挡着个“更⾼”的
//元素， 所以他们不可能被作为后续进来的元素的 Next Great Number 了。
//这个算法的时间复杂度不是那么直观， 如果你看到 for 循环嵌套 while 循
//环， 可能认为这个算法的复杂度也是 O(n ^ 2)， 但是实际上这个算法的复杂
//度只有 O(n)。
template<typename T>
vector<T> nextGreaterElement(vector<T>& nums) {
    vector<T> ans(nums.size());
    stack<T> s;
    // 倒着往栈⾥放
    for (int i = nums.size() - 1; i >= 0; i--) {
        // 判定个⼦⾼矮
        while (!s.empty() && s.top() <= nums[i]) {
            // 矮个起开， 反正也被挡着了。 。 。
            s.pop();
        }
        // 这个元素⾝后的第⼀个⾼个
        ans[i] = s.empty() ? -1 : s.top();
        // 进队， 接受之后的⾝⾼判定吧！
        s.push(nums[i]);
    }
    return ans;
}


template<typename T>
vector<T> dailyTemperatures(vector<T>& nums) {
    vector<T> ans(nums.size());
    stack<T> s; // 这⾥放元素索引， ⽽不是元素
    // 倒着往栈⾥放
    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!s.empty() && nums[s.top()] <= nums[i]) {
            s.pop();
        }
        // 得到索引间距
        ans[i] = s.empty() ? 0 : (s.top() - i);
        // 加⼊索引， ⽽不是元素
        s.push(i);
    }
    return ans;
}


// 如何处理「循环数组」
template<typename T>
vector<T> nextGreaterElementLoop(vector<T>& nums) {
    int n = nums.size();
    vector<T> ans(n);
    stack<T> s;
    // 倒着往栈⾥放
    for (int i = 2*n - 1; i >= 0; i--) {
        // 判定个⼦⾼矮
        while (!s.empty() && s.top() <= nums[i%n]) {
            // 矮个起开， 反正也被挡着了。 。 。
            s.pop();
        }
        // 这个元素⾝后的第⼀个⾼个
        ans[i%n] = s.empty() ? -1 : s.top();
        // 进队， 接受之后的⾝⾼判定吧！
        s.push(nums[i%n]);
    }
    return ans;
}


int main()
{
    cout << "Hello World!\n";
    vector<int> nums = { 73, 74, 75, 71, 69, 72, 76, 73 };
    vector<int> ans;
    ans = nextGreaterElementLoop<int>(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;


}

