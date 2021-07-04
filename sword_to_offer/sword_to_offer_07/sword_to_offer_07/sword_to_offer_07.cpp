// sword_to_offer_07.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
剑指 Offer 07. 重建二叉树
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。



例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7


限制：

0 <= 节点个数 <= 5000
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
private:
    unordered_map<int, int> index;

public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, 
        int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) return nullptr;

        // 先把根节点建立出来
        TreeNode* root = new TreeNode(preorder[preorder_left]);

        // 在中序遍历中定位根节点
        int inorder_root_pos = index[preorder[preorder_left]];

        // 得到左子树中的节点数目
        int left_L = inorder_root_pos - inorder_left;

        // 递归地构造左子树，并连接到根节点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + left_L, inorder_left, inorder_root_pos - 1);

        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = myBuildTree(preorder, inorder, preorder_left + left_L + 1, preorder_right, inorder_root_pos + 1, inorder_right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
 
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};


void preorderPrint(TreeNode* root) {
    if (root != nullptr) {
        cout << root->val << " ";
        preorderPrint(root->left);
        preorderPrint(root->right);
    }
}


int main()
{
    Solution S;
    vector<int> preorder = { 3,9,20,15,7 };
    vector<int> inorder = { 9,3,15,20,7 };
    TreeNode* root = S.buildTree(preorder, inorder);
    preorderPrint(root);
}

