#pragma once

#include <iostream>
#include <queue>
using namespace std;


template<typename T>
class Node {
public:
	T value;
	Node<T>* left;
	Node<T>* right;
public:
	Node(T val) {
		left = nullptr;
		right = nullptr;
		value = val;
	}
};


template<typename T>
class BST
{
private:
	Node<T>* root;

public:
	BST() {
		root = nullptr;
	}
	BST(T val) {
		root = new Node<T>(val);
	}
	~BST() {
		delete root;
		root = nullptr;
	}

public:
	//在 BST 中插⼊⼀个数
	Node<T>* insert(Node<T>* root, T val) {
		if (root == nullptr) {
			root = new Node<T>(val);
			return root;
		}
		if (root->value < val) {
			root->right = insert(root->right, val);
		}
		if (root->value > val) {
			root->left = insert(root->left, val);
		}
		return root;
	}

	void insertIntoBST(T val) {
		root = insert(root, val);
	}

	//在 BST 中删除⼀个数
	Node<T>* deleteNode(Node<T>* root, int key) {
		if (root == nullptr) return nullptr;
		if (root->value == key) {
			// 找到了，进行删除
			// 情况 1： A 恰好是末端节点， 两个⼦节点都为空， 那么它可以当场去世了
			if (root->left == nullptr && root->right == nullptr) {
				delete root;
				root = nullptr;
				return root;
			}
			// 情况 2： A 只有⼀个⾮空⼦节点， 那么它要让这个孩⼦接替⾃⼰的位置
			if (root->left == nullptr) {
				return root->right;
			}
			if (root->right == nullptr) {
				return root->left;
			}
			// 情况 3： A 有两个⼦节点， ⿇烦了， 为了不破坏 BST 的性质， A 必须找到
			// 左⼦树中最⼤的那个节点， 或者右⼦树中最⼩的那个节点来接替⾃⼰。
			if (root->left != nullptr && root->right != nullptr) {
				// 找到右子树最小的节点
				Node<T>* minNode = getMin(root->right);
				// 把 root 改成 minNode
				root->value = minNode->value;
				// 转⽽去删除 minNode
				root->right = deleteNode(root->right, minNode->value);
			}
		}
		else if (root->value > key) {
			root->left = deleteNode(root->left, key);
		}
		else if (root->value < key) {
			root->right = deleteNode(root->right, key);
		}
		return root;
	}


public:
	Node<T>* getRoot() {
		return root;
	}

	// 获取右子树最小的值
	Node<T>* getMin(Node<T>* node) {
		while (node->left != nullptr) node = node->left;
		return node;
	}

	// 遍历一棵树
	// 前序遍历
	void PreOrderTraverse(Node<T>* root) {
		if (root != nullptr) {
			cout << root->value << " ";
		}
		else {
			return;
		}
		PreOrderTraverse(root->left);
		PreOrderTraverse(root->right);
	}
	// 中序遍历
	void InOrderTraverse(Node<T>* root) {
		if (root == nullptr) return;
		InOrderTraverse(root->left);
		cout << root->value << " ";
		InOrderTraverse(root->right);
	}
	// 后序遍历
	void PostOrderTraverse(Node<T>* root) {
		if (root == nullptr) return;
		PostOrderTraverse(root->left);
		PostOrderTraverse(root->right);
		cout << root->value << " ";
	}
	// 层次遍历
	void LevelTraverse(Node<T>* root) {
		queue<Node<T>*> Q;
		Q.push(root);
		while (!Q.empty()) {
			Node<T>* node = Q.front();
			Q.pop();
			cout << node->value << " ";
			if (node->left != nullptr) Q.push(node->left);
			if (node->right != nullptr) Q.push(node->right);
		}
	}
	void printBST() {
		cout << "前序遍历: " << endl;
		PreOrderTraverse(root);
		cout << endl;
		cout << "中序遍历: " << endl;
		InOrderTraverse(root);
		cout << endl;
		cout << "后序遍历: " << endl;
		PostOrderTraverse(root);
		cout << endl;
		cout << "层次遍历: " << endl;
		LevelTraverse(root);
		cout << endl;
	}
};

