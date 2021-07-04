/*
337. 打家劫舍 III
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。
除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \
     3   1

输出: 7
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
示例 2:

输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
*/

#include <iostream>
#include <unordered_map>
#include <cmath>
#include <queue>
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
    unordered_map <TreeNode*, int> f, g;
    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        dfs(node->left);
        dfs(node->right);
        f[node] = node->val + g[node->left] + g[node->right];
        g[node] = max(f[node->left], g[node->left]) + max(f[node->right], g[node->right]);
    }

    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root], g[root]);
    }
};


TreeNode* CreatBiTree(int *a, int n, int start) {
    if (a[start] == '#') return nullptr;
    TreeNode* root = new TreeNode(a[start]);

    int lnode = 2 * start + 1;
    int rnode = 2 * start + 2;

    if (lnode < n) {
        root->left = CreatBiTree(a, n, lnode);
    }
    if (rnode < n) {
        root->right = CreatBiTree(a, n, rnode);
    }

    return root;
}

//层序遍历--队列
void LevelOrderTraverse(TreeNode* T) {
    queue<TreeNode*> Q;
    if (T == nullptr) return;
    Q.push(T);
    while (!Q.empty()) {
        TreeNode* cur = Q.front();
        Q.pop();
        cout << cur->val << " ";
        if (cur->left) Q.push(cur->left);
        if (cur->right) Q.push(cur->right);
    }
    cout << endl;
}


int main()
{
    std::cout << "Hello World!\n";
    Solution S;
    int a[] = { 3, 2, 3, '#', 3, '#', 1 };
    int length = sizeof(a) / sizeof(a[0]);
    TreeNode* root = CreatBiTree(a, length, 0);
    LevelOrderTraverse(root);
    

    cout << S.rob(root) << endl;

    
}
