// leetcode_382_Linked_List_Random_Node.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
382. 链表随机节点
给定一个单链表，随机选择链表的一个节点，并返回相应的节点值。保证每个节点被选的概率一样。

进阶:
如果链表十分大且长度未知，如何解决这个问题？你能否使用常数级空间复杂度实现？

示例:

// 初始化一个单链表 [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom()方法应随机返回1,2,3中的一个，保证每个元素被返回的概率相等。
solution.getRandom();
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
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
private:
    ListNode* head;

public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
        srand(time(NULL));
    }

    /** Returns a random node's value. */
    int getRandom() {
        int i = 0, res = 0;
        ListNode* p = head;
        while (p != nullptr) {
            if (rand() % (++i) == 0) {
                res = p->val;
            }
            p = p->next;
        }       
        return res;
    }

    vector<int> getKRandom(int k) {
        vector<int> res;
        ListNode* p = head;

        // 前 k 个元素先默认选上
        for (int j = 0; j < k && p != nullptr; j++) {
            res.push_back(p->val);
            p = p->next;
        }

        int i = k;

        while (p != nullptr) {
            int j = rand() % (++i);
            if (j < k) {
                res[j] = p->val;
            }
            p = p->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main()
{
    std::cout << "Hello World!\n";
    // 初始化一个单链表 [1,2,3].
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution* solution = new Solution(head);

    // getRandom()方法应随机返回1,2,3中的一个，保证每个元素被返回的概率相等。
    int param_1 = solution->getRandom();
    cout << param_1 << endl;

    vector<int> res = solution->getKRandom(2);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;


    return -1;
}

