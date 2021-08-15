// leetcode_113_Path_Sum_II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
113. 路径总和 II
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。



示例 1：


输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]
示例 2：


输入：root = [1,2,3], targetSum = 5
输出：[]
示例 3：

输入：root = [1,2], targetSum = 0
输出：[]


提示：

树中节点总数在范围 [0, 5000] 内
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
*/

#include <iostream>
#include <vector>
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
    void dfs(TreeNode* root, int& targetSum, vector<int>& track, int& cur, vector<vector<int>>& res) {
        if (root->left == nullptr && root->right == nullptr) {
            if (cur == targetSum) {
                res.push_back(track);
            }
            return;
        }

        if (root->left != nullptr) {
            track.push_back(root->left->val);
            cur = cur + root->left->val;
            dfs(root->left, targetSum, track, cur, res);
            track.pop_back();
            cur = cur - root->left->val;
        }

        if (root->right != nullptr) {
            track.push_back(root->right->val);
            cur = cur + root->right->val;
            dfs(root->right, targetSum, track, cur, res);
            track.pop_back();
            cur = cur - root->right->val;
        }
        

        return;
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return {};

        vector<vector<int>> res = {};
        vector<int> track = { root->val };
        int cur = root->val;

        dfs(root, targetSum, track, cur, res);

        return res;
    }
};



int main()
{
    std::cout << "Hello World!\n";
}


