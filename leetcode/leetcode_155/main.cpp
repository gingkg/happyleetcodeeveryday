#include <iostream>
#include <stack> 
#include <algorithm>
using namespace std;

/*
155. ��Сջ
���һ��֧�� push ��pop ��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
push(x) ���� ��Ԫ�� x ����ջ�С�
pop() ���� ɾ��ջ����Ԫ�ء�
top() ���� ��ȡջ��Ԫ�ء�
getMin() ���� ����ջ�е���СԪ�ء�

ʾ��:

���룺
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

�����
[null,null,null,null,-3,null,0,-2]

���ͣ�
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> ���� -3.
minStack.pop();
minStack.top();      --> ���� 0.
minStack.getMin();   --> ���� -2.

��ʾ��
pop��top �� getMin ���������� �ǿ�ջ �ϵ��á�
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
    cout << "����ĳ���Ϊ��" << L1 << endl;
    cout << "����ĳ���Ϊ��" << L2 << endl;
    for (int i = 0; i < L1; i++) {
        cout << op[i] << endl;
    }
    cout << "=====================" << endl;
    for (int j = 0; j < L2; j++) {
        cout << ch[j][0] << endl;
    }





    return 0;
}