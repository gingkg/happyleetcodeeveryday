﻿// leetcode_141_Linked_List_Cycle.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
141. 环形链表
给定一个链表，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

如果链表中存在环，则返回 true 。 否则，返回 false 。



进阶：

你能用 O(1)（即，常量）内存解决此问题吗？



示例 1：



输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
示例 2：



输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。
示例 3：



输入：head = [1], pos = -1
输出：false
解释：链表中没有环。


提示：

链表中节点的数目范围是 [0, 104]
-105 <= Node.val <= 105
pos 为 -1 或者链表中的一个 有效索引 。
*/

#include <iostream>
#include <vector>
using namespace std;


// Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode *fast=head, *slow=head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }
};



int main()
{
    vector<int> list = { 3,2,0,-4 };
    int pos = 1;
    ListNode* head = nullptr;
    ListNode* targetPos = nullptr;
    if (list.size() > 0) {
        head = new ListNode(list[0]);
    }
    ListNode* p = head;
    if (pos == 0) {
        targetPos = head;
    }
    for (int i = 1; i < list.size(); i++) {
        if (p != nullptr) {
            p->next = new ListNode(list[i]);
            p = p->next;
        }
        if (pos == i) targetPos = p;
    }
    if(p != nullptr) p->next = targetPos;
    p = head;
    

    Solution S;
    cout << S.hasCycle(head) << endl;

    return 0;
}


