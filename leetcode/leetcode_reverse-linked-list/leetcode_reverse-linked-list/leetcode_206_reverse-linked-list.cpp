// leetcode_reverse-linked-list.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
206. 反转链表
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/

#include <iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 迭代
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* tail = head;
        ListNode* ans;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        ans = tail;
        
        while (head != tail) {
            ListNode* p = head;
            while (p->next != tail) {
                p = p->next;
            }
            tail->next = p;
            tail = p;
        }
        tail->next = nullptr;
        return ans;
    }
};


// 递归
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        if (head->next == nullptr) {
            return head;
        }
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};


int main()
{
    cout << "Hello World!\n";
}

Line 24: Char 16 : error : use of undeclared identifier 'last'
return last;
^
1 error generated.