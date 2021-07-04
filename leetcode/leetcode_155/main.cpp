#include <iostream>
#include <stack> 
#include <algorithm>
using namespace std;

/*
155. 最小栈
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。

示例:

输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

提示：
pop、top 和 getMin 操作总是在 非空栈 上调用。
*/


class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }

    void push(int x) {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }

    void pop() {
        x_stack.pop();
        min_stack.pop();
    }

    int top() {
        return x_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};


int main()
{
    string op[] = { "MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin" };
    int ch[][1] = { {} ,{-2},{0},{-3},{},{},{},{} };
    int L1,L2;
    L1 = end(op) - begin(op);
    L2 = end(ch) - begin(ch);
    cout << "数组的长度为：" << L1 << endl;
    cout << "数组的长度为：" << L2 << endl;
    for (int i = 0; i < L1; i++) {
        cout << op[i] << endl;
    }
    cout << "=====================" << endl;
    for (int j = 0; j < L2; j++) {
        cout << ch[j][0] << endl;
    }





    return 0;
}