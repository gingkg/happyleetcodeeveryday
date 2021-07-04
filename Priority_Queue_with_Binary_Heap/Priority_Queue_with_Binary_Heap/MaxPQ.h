#pragma once

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template <class T>
class MaxPQ
{
private:
	// 存储元素的数组
	vector<T> pq;
	// 当前 Priority Queue 中的元素个数
	int N = 0;

public:
	MaxPQ();
	MaxPQ(int cap);


public:
	/*返回当前队列中最大元素 */
	T max();
	/*插入元素 e */
	void insert(T e);
	/* 删除并返回当前队列中最大元素 */
	T delMax();
	/* 上浮第 k 个元素， 以维护最大堆性质 */
	void swim(int k);
	/* 下沉第 k 个元素， 以维护最大堆性质 */
	void sink(int k);
	// 交换数组中的两个元素
	void exch(int i, int j);
	// pq[i] 是否比 pq[j]小？
	bool less(int i, int j);
	// left, right, parent三个方法
	int parent(int root);
	int left(int root);
	int right(int root);

public:
	int capacity() {
		return pq.size();
	}
	int size() {
		return N;
	}
	void print() {
		for (int i = 1; i <= N; i++) {
			cout << pq[i] << " ";
		}
		cout << endl;
	}

};


template<class T>
MaxPQ<T>::MaxPQ()
{
	pq = vector<T>(100 + 1);
}

template <class T>
MaxPQ<T>::MaxPQ(int cap) {
	// 索引 0 不用， 所以多分配一个空间
	pq = vector<T>(cap + 1);
}

template<class T>
T MaxPQ<T>::max()
{
	return pq[1];
}


template<class T>
void MaxPQ<T>::insert(T e)
{
	//insert ⽅法先把要插⼊的元素添加到堆底的最后， 然后让其上浮到正确位置。
	N++;
	if (N >= capacity()) {
		pq.resize(ceil(capacity() * 1.25));
	}
	pq[N] = e;
	swim(N);
}

template<class T>
T MaxPQ<T>::delMax()
{
	// delMax ⽅法先把堆顶元素 A 和堆底最后的元素 B 对调， 然后删除 A， 最后让 B 下沉到正确位置
	// 最⼤堆的堆顶就是最⼤元素
	T max = pq[1];
	// 把这个最⼤元素换到最后， 删除之
	exch(1, N);
	pq.pop_back();
	//pq[N] = NULL;
	N--;
	sink(1);
	return max;
}

template<class T>
void MaxPQ<T>::swim(int k)
{
	// 如果浮到堆顶， 就不能再上浮了
	while (k > 1 && less(parent(k), k)) {
		// 如果第 k 个元素⽐上层⼤
		// 将 k 换上去
		exch(parent(k), k);
		k = parent(k);
	}
}

template<class T>
void MaxPQ<T>::sink(int k)
{
	// 如果沉到堆底， 就沉不下去了
	while (left(k) <= N) {
		// 先假设左边节点较⼤
		int older = left(k);
		// 如果右边节点存在， ⽐⼀下⼤⼩
		if (right(k) <= N && less(older, right(k))) {
			older = right(k);
		}
		// 结点 k ⽐俩孩⼦都⼤， 就不必下沉了
		if (less(older, k)) break;
		// 否则， 不符合最⼤堆的结构， 下沉 k 结点
		exch(k, older);
		k = older;
	}
}

template<class T>
void MaxPQ<T>::exch(int i, int j) {
	T temp = pq[i];
	pq[i] = pq[j];
	pq[j] = temp;
}

template<class T>
bool MaxPQ<T>::less(int i, int j)
{
	return pq[i] < pq[j];
}

template<class T>
int MaxPQ<T>::parent(int root)
{
	return root / 2;
}

template<class T>
int MaxPQ<T>::left(int root)
{
	return root * 2;
}

template<class T>
int MaxPQ<T>::right(int root)
{
	return root * 2 + 1;
}