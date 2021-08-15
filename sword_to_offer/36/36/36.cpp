// 36.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
剑指 Offer 36. 二叉搜索树与双向链表
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。


为了让您更好地理解问题，以下面的二叉搜索树为例：

我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。
下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。

特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。

注意：本题与主站 426 题相同：https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

注意：此题对比原题有改动。
*/

#include <iostream>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    void backtrack(Node* root, Node*& head, Node*& tail) {
        if (root->left == nullptr && root->right == nullptr) {
            head = root;
            tail = root;
            return;
        }

        if (root->left != nullptr && root->right == nullptr) {
            tail = root;
            Node* head_ = nullptr;
            Node* tail_ = nullptr;
            backtrack(root->left, head_, tail_);
            root->left = tail_;
            tail_->right = root;
            head = head_;
            return;
        }

        if (root->left != nullptr && root->right == nullptr) {
            head = root;
            Node* head_ = nullptr;
            Node* tail_ = nullptr;
            backtrack(root->right, head_, tail_);
            root->right = head_;
            head_->left = root;
            tail = tail_;
            return;
        }

        Node* leftHead_ = nullptr;
        Node* leftTail_ = nullptr;
        Node* rightHead_ = nullptr;
        Node* rightTail_ = nullptr;

        backtrack(root->left, leftHead_, leftTail_);
        backtrack(root->right, rightHead_, rightTail_);

        root->left = leftTail_;
        leftTail_->right = root;
        root->right = rightHead_;
        rightHead_->left = root;

        head = leftHead_;
        tail = rightTail_;

        return;
    }



    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node* head = nullptr;
        Node* tail = nullptr;

        backtrack(root, head, tail);

        head->left = tail;
        tail->right = head;

        return head;
    }
};


int main()
{
    
}


