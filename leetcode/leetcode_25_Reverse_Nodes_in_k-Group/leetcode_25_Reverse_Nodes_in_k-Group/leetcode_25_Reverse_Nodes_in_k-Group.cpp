// leetcode_25_Reverse_Nodes_in_k-Group.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
25. K 个一组翻转链表
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

进阶：

你可以设计一个只使用常数额外空间的算法来解决此问题吗？
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。


示例 1：


输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]
示例 2：


输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]
示例 3：

输入：head = [1,2,3,4,5], k = 1
输出：[1,2,3,4,5]
示例 4：

输入：head = [1], k = 1
输出：[1]
提示：

列表中节点的数量在范围 sz 内
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz
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
    ListNode* reverse(ListNode* head, ListNode* end) {
        ListNode* pre = nullptr, * cur = head, * nxt = head;
        while (cur != end) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode* start = head, * end = head;
        for (int i = 0; i < k; i++) {
            if (end == nullptr) return head;
            end = end->next;
        }
        ListNode* newHead = reverse(start, end);
        start->next = reverseKGroup(end, k);
        return newHead;
    }
};


int main()
{
    std::cout << "Hello World!\n";
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    for (int i = 1; i <= 11; i++) {
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
    int k = 3;
    ListNode* res = S.reverseKGroup(head, k);
    p = res;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

