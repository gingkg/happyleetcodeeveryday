// leetcode_142_ Linked_List_Cycle_2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

/*
142. 环形链表 II
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。

进阶：

你是否可以使用 O(1) 空间解决此题？


示例 1：



输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。
示例 2：



输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。
示例 3：



输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。


提示：

链表中节点的数目范围在范围 [0, 104] 内
-105 <= Node.val <= 105
pos 的值为 -1 或者链表中的一个有效索引
*/

#include <iostream>
#include <vector>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head, * slow = head;
        bool flag = false;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                flag = true;
                break;
            }
        }

        if (!flag) return nullptr;

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
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
    if (p != nullptr) p->next = targetPos;
    p = head;


    Solution S;
    ListNode* res = S.detectCycle(head);
    cout << res->val << endl;

    return 0;
}
