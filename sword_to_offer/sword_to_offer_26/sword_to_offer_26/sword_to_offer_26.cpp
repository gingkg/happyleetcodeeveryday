// sword_to_offer_26.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
剑指 Offer 26. 树的子结构
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

示例 1：

输入：A = [1,2,3], B = [3,1]
输出：false
示例 2：

输入：A = [3,4,5,1,2], B = [4,1]
输出：true
限制：

0 <= 节点个数 <= 10000
*/

#include <iostream>
#include <queue>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    bool isSame(TreeNode* A, TreeNode* B) {
        if (A != nullptr && B != nullptr) {
            if (A->val != B->val) return false;
            if (!isSame(A->left, B->left)) return false;
            if (!isSame(A->right, B->right)) return false;
            return true;
        }
        else if (A == nullptr && B != nullptr) {
            return false;
        }
        else {
            return true;
        }
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) return false;
        queue<TreeNode*> Q;
        Q.push(A);
        while (!Q.empty()) {
            TreeNode* p = Q.front();
            Q.pop();
            if (isSame(p, B)) return true;
            if (p->left != nullptr) Q.push(p->left);
            if (p->right != nullptr) Q.push(p->right);
        }
        return false;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}


