#pragma once

#include <iostream>
#include <queue>
using namespace std;

template<typename T>
class MyStack
{
private:
	queue<T> q;
public:
	/** 添加元素到栈顶 */
	void push(T x) {
		q.push(x);
	}

	/** 添加元素到栈顶 */
	T pop() {
		int size = q.size();
		while (size > 1) {
			T temp = q.front();
			q.pop();
			q.push(temp);
			size--;
		}
		T temp = q.front();
		q.pop();
		return temp;
	}

	/** 返回栈顶元素 */
	T top() {
		return q.back();
	}

	/** 返回栈顶元素 */
	bool empty() {
		return q.empty();
	}

};

