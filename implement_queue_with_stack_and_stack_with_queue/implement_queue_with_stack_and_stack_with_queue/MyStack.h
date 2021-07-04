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
	/** ���Ԫ�ص�ջ�� */
	void push(T x) {
		q.push(x);
	}

	/** ���Ԫ�ص�ջ�� */
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

	/** ����ջ��Ԫ�� */
	T top() {
		return q.back();
	}

	/** ����ջ��Ԫ�� */
	bool empty() {
		return q.empty();
	}

};

