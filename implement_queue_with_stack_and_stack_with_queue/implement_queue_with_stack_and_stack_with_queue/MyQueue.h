#pragma once

#include<iostream>
#include<stack>
using namespace std;

template<typename T>
class MyQueue
{
private:
	stack<T> s1, s2;

public:
	MyQueue() {}

public:
	/** 添加元素到队尾 */
	void push(T x) {
		s1.push(x);
	}

	/** 添加元素到队尾 */
	T pop() {
		T temp = fornt();
		s2.pop();
		return temp;
	}
	
	/** 返回队头元素 */
	T fornt() {
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		return s2.top();
	}

	/** 判断队列是否为空 */
	bool empty() {
		return s1.empty() && s2.empty();
	}
};

