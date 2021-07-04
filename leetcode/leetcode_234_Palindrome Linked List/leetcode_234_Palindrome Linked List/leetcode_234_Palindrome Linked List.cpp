// leetcode_234_Palindrome Linked List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
234. 回文链表
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next != nullptr) {
            ListNode* tail = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
            return tail;
        }
        else {
            return head;
        }
    }

    ListNode* reverseList2(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        } 
        return pre;
    }

    ListNode* copyReverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* newHead = new ListNode(head->val);
        ListNode* p = head;
        ListNode* newP = newHead;
        while (p->next != nullptr) {
            newP->next = new ListNode(p->next->val);
            p = p->next;
            newP = newP->next;
        }
        return reverseList(newHead);
    }

    bool traverse(ListNode*& left, ListNode* right) {
        if (right == nullptr) return true;
        bool res = traverse(left, right->next);
        res = res && (right->val == left->val);
        left = left->next;
        return res;
    }

    //void traverse(ListNode* head) {
    //    if (head == nullptr) return;
    //    traverse(head->next);
    //    // 后序遍历代码
    //    cout << head->val << endl;
    //}

    bool isPalindrome(ListNode* head) {
        ListNode* slow, * fast;
        slow = fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != nullptr) {
            slow = slow->next;
        }
        ListNode* left = head;
        ListNode* right = reverseList(slow);
        while (left != nullptr && right != nullptr) {
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};


int main()
{
    cout << "Hello World!\n";
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    for (int i = 1; i < 10; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }
    
    p = head;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    Solution S;
    ListNode* tail = S.copyReverseList(head);

    p = tail;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    cout << S.isPalindrome(head) << endl;

}
