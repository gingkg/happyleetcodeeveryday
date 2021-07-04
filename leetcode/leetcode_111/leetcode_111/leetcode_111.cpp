/*
111. 二叉树的最小深度
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明：叶子节点是指没有子节点的节点。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：2

示例 2：
输入：root = [2,null,3,null,4,null,5,null,6]
输出：5

执行用时：264 ms
内存消耗：141.2 MB

https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/submissions/
*/


#include <iostream>
#include <queue>
#include <list>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        while (!q.empty()) {
            int sz = q.size();
            /* 将当前队列中的所有节点向四周扩散 */
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                /* 判断是否到达终点 */
                if (cur->left == nullptr && cur->right == nullptr) {
                    return depth;
                }
                /* 将 cur 的相邻节点加⼊队列 */
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
            depth++;
        }
        return depth;
    }
};

int main()
{
    cout << "Hello World!\n";
    int tree[] = { 2, NULL, 3, NULL, 4, NULL, 5, NULL, 6, 0 };
    int L = sizeof((tree)) / sizeof(tree)[0];
    cout << L << endl;
    for (int i : tree) {
        if (i == NULL) {
            cout << "NULL" << " ";
        }
        else {
            cout << i << " ";
        }
        
    }
    cout << endl;

    TreeNode* root = new TreeNode(2);
    TreeNode* p = root;
    
    for (int i = 0; i < 5; i++) {
        p->right = new TreeNode(i);
        p = p->right;
        cout << p->val << endl;
    }

    cout << root->val << endl;
    cout << root->right->val << endl;
    cout << p->val << endl;

    p = root;
    for (int i = 0; i <= 5; i++) {
        cout << p->val << " ";
        p = p->right;
    }
    cout << endl;

    Solution S;

    cout << S.minDepth(root) << endl;
    

    return 0;
}

