#pragma once

/*
LRU 缓存淘汰算法就是⼀种常⽤策略。 LRU 的全称是 Least Recently
Used， 也就是说我们认为最近使⽤过的数据应该是是「有⽤的」 ， 很久都
没⽤过的数据应该是⽆⽤的， 内存满了就优先删那些很久没⽤过的数据。

当然还有其他缓存淘
汰策略， ⽐如不要按访问的时序来淘汰， ⽽是按访问频率（LFU 策略） 来
淘汰等等， 各有应⽤场景。

这个数据结构必要的条件： 查找快， 插⼊快， 删除快， 有顺序之分。
LRU 缓存算法的核⼼数据结构就是哈希链表， 双向链表和哈希表的结合体。
*/

#include <iostream>
#include <cassert>
#include <unordered_map>
using namespace std;

// 双链表的节点类
template <class KEY, class VALUE>
class Node {
public:
	KEY key;
	VALUE value;
	Node<KEY, VALUE> *next, *prev;
public:
	Node(const KEY& k, const VALUE& v) {
		key = k;
		value = v;
		next = nullptr;
		prev = nullptr;
	}
};

// 依靠我们的 Node 类型构建⼀个双链表， 实现⼏个需要的 API（这些操作的时间复杂度均为 O(1) )
template <class KEY, class VALUE>
class DoubleList {
public:
	Node<KEY, VALUE> *head, *tail;
	int N = 0;

public:
	DoubleList() {
		head = new Node<KEY, VALUE>(NULL, NULL);
		tail = new Node<KEY, VALUE>(NULL, NULL);
		head->next = tail;
		tail->prev = head;
	}

	~DoubleList() {
		delete head, tail;
		head = nullptr;
		tail = nullptr;
	}

public:
	// 在链表头部添加节点 x， 时间 O(1)
	void addFirst(Node<KEY, VALUE> *x) {
		x->next = head->next;
		head->next = x;
		x->next->prev = x;
		x->prev = head;
		N++;
	}
	// 删除链表中的 x 节点（x ⼀定存在）
	// 由于是双链表且给的是⽬标 Node 节点， 时间 O(1)
	void remove(Node<KEY, VALUE> *x) {
		cout << x << " " << x->key << " " << x->value<< endl;
		assert(x != head && x != tail && x != nullptr);
		x->prev->next = x->next;
		x->next->prev = x->prev;
		x->prev = nullptr;
		x->next = nullptr;
		N--;
	}
		
	// 删除链表中最后⼀个节点， 并返回该节点， 时间 O(1)
	Node<KEY, VALUE>* removeLast() {
		Node<KEY, VALUE>* x = tail->prev;
		if (x == head) {
			x = nullptr;
		}
		else {
			remove(x);
		}
		return x;
	}
	// 返回链表⻓度， 时间 O(1)
	int size() {
		return N;
	}
	// 遍历输出
	void print() {
		Node<KEY, VALUE> *p = head->next;
		while (p != NULL && p->next != nullptr) {
			cout <<&(*p)<<" "<< p->key << " " << p->value << endl;
			p = p->next;
		}
	}

};



template <class KEY, class VALUE>
class LRUCache
{
private:
	unordered_map<KEY, Node<KEY, VALUE>*> map;
	DoubleList<KEY, VALUE> cache;
	Node<KEY, VALUE>* x;
	int cap;

public:
	LRUCache(int capacity) {
		cap = capacity;
		x = nullptr;
		cout << cap << endl;
	}
	~LRUCache(){
		delete x;
		x = nullptr;
	}

public:
	VALUE get(KEY key) {
		if (!map.count(key)) {
			return -1;
		}
		VALUE val = map.at(key)->value;
		put(key, val);
		return val;
	}

	void put(KEY key, VALUE val) {
		x = new Node<KEY, VALUE>(key, val);
		
		if (map.count(key)) {
			// 删除旧的节点， 新的插到头部
			cache.remove(map.at(key));
			cache.addFirst(x);
			// 更新 map 中对应的数据
			map.emplace(key, x);
		}
		else {
			if (cap == cache.size()) {
				// 删除链表最后⼀个数据
				Node<KEY, VALUE>* last = cache.removeLast();
				if (last != nullptr) {
					map.erase(last->key);
				}
			}
			// 直接添加到头部
			cache.addFirst(x);
			map.emplace(key, x);
		}
	}

	void print() {
		typename unordered_map<KEY, Node<KEY, VALUE>*>::iterator iter;
		for (iter = map.begin(); iter != map.end(); iter++) {
			cout << iter->second << " " << iter->first << "->(" << (iter->second)->key << "," << (iter->second)->value << ")" << endl;
		}
		cache.print();
	}
};

