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
	/** ���Ԫ�ص���β */
	void push(T x) {
		s1.push(x);
	}

	/** ���Ԫ�ص���β */
	T pop() {
		T temp = fornt();
		s2.pop();
		return temp;
	}
	
	/** ���ض�ͷԪ�� */
	T fornt() {
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		return s2.top();
	}

	/** �ж϶����Ƿ�Ϊ�� */
	bool empty() {
		return s1.empty() && s2.empty();
	}
};

