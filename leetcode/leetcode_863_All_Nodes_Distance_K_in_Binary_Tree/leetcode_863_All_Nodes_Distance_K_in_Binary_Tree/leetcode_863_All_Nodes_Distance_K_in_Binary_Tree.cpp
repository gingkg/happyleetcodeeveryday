// leetcode_863_All_Nodes_Distance_K_in_Binary_Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
863. 二叉树中所有距离为 K 的结点
给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 K 。

返回到目标结点 target 距离为 K 的所有结点的值的列表。 答案可以以任何顺序返回。



示例 1：

输入：root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
输出：[7,4,1]
解释：
所求结点为与目标结点（值为 5）距离为 2 的结点，
值分别为 7，4，以及 1



注意，输入的 "root" 和 "target" 实际上是树上的结点。
上面的输入仅仅是对这些对象进行了序列化描述。


提示：

给定的树是非空的。
树上的每个结点都具有唯一的值 0 <= node.val <= 500 。
目标结点 target 是树上的结点。
0 <= K <= 1000.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
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
    vector<TreeNode*> track;
    vector<int> result;

    bool getTrack(TreeNode* root, TreeNode* target) {
        if (root == nullptr) return false;

        if (root == target) {
            track.push_back(root);
            return true;
        }

        if (getTrack(root->left, target)) {
            track.push_back(root);
            return true;
        }

        if (getTrack(root->right, target)) {
            track.push_back(root);
            return true;
        }

        return false;
    }

    void search(TreeNode* root, int k, int i) {
        if (root == nullptr) return;

        if (k == i) {
            result.push_back(root->val);
            return;
        }

        search(root->left, k, i + 1);
        search(root->right, k, i + 1);

        return;
    }



    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        getTrack(root, target);

        for (int i = 0; i < track.size(); i++) {
            TreeNode* cur = track[i];
            if (i > 0) {
                TreeNode* child = track[i - 1];
                if (cur->left == child) {
                    cur->left = nullptr;
                }
                else if (cur->right == child) {
                    cur->right = nullptr;
                }
            }

            search(cur, k - i, 0);
        }

        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

