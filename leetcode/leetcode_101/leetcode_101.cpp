/*
101. 对称二叉树
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3
 
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
    1
   / \
  2   2
   \   \
   3    3
 
进阶：
你可以运用递归和迭代两种方法解决这个问题吗？
1、递归
执行用时: 8 ms
内存消耗: 11.9 MB
我们可以实现这样一个递归函数，通过「同步移动」两个指针的方法来遍历这棵树，pp 指针和 qq 指针一开始都指向这棵树的根，
随后 pp 右移时，qq左移，pp 左移时，qq 右移。每次检查当前 pp 和 qq 节点的值是否相等，如果相等再判断左右子树是否对称。

复杂度分析
假设树上一共 nn 个节点。
时间复杂度：这里遍历了这棵树，渐进时间复杂度为 O(n)O(n)。
空间复杂度：这里的空间复杂度和递归使用的栈空间有关，这里递归层数不超过 nn，故渐进空间复杂度为 O(n)O(n)。

2、迭代
执行用时: 0 ms
内存消耗: 12.6 MB
首先我们引入一个队列，这是把递归程序改写成迭代程序的常用方法。初始化时我们把根节点入队两次。
每次提取两个结点并比较它们的值（队列中每两个连续的结点应该是相等的，而且它们的子树互为镜像），
然后将两个结点的左右子结点按相反的顺序插入队列中。
当队列为空时，或者我们检测到树不对称（即从队列中取出两个不相等的连续结点）时，该算法结束。

复杂度分析
时间复杂度：O(n)O(n)，同「方法一」。
空间复杂度：这里需要用一个队列来维护节点，每个节点最多进队一次，出队一次，队列中最多不会超过 nn 个点，故渐进空间复杂度为 O(n)O(n)。
*/



#include <iostream>
#include <stack> 
#include <queue>
#include <string>
#include <cstring>
using namespace std;



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 构建一棵树
// 包含两个功能：1、根据给定数组构建一棵树；2、输出树得根节点
class Tree {
private:
    TreeNode *root;
    int RefValue;

public:
    //==========二叉树构造与析构==========//
    //构造函数
    Tree() : RefValue(0), root(NULL) {}

    //指定结束标志的构造函数
    Tree(int value) : RefValue(value), root(NULL) {}

    //析构函数
    ~Tree() { Destroy(root); }

    //==========成员函数==========//
    //销毁函数
    void Destroy() { Destroy(root); }
    // 构建树
    //前序遍历创建二叉树(前序遍历的应用)，用#表示空结点
    void CreateBinTree_PreOrder(int list[]) { 
        int i = 0;
        i = CreateBinTree_PreOrder(root, i, list); 
        cout << i << endl;
    }

    //层次遍历(非递归)
    void LevelOrder() { LevelOrder(root); }

    //获取二叉树的根节点
    TreeNode* getRoot() const {
        return root;
    }


protected:
    //创建二叉树(利用已知的二叉树的前序遍历创建)用#表示空结点
    int CreateBinTree_PreOrder(TreeNode*& subTree, int i, int list[])
    {
        int item = list[i];
        i++;
        if (item != RefValue)
        {
            subTree = new TreeNode(item); //构造结点
            if (subTree == NULL)
            {
                cout << "空间分配错误！" << endl;
                exit(1);
            }
            i = CreateBinTree_PreOrder(subTree->left, i, list);  //递归创建左子树
            i = CreateBinTree_PreOrder(subTree->right, i, list); //递归创建右子树
        }
        else
        {
            subTree = NULL;
        }
        return i;
    }

    //层次遍历(非递归)
    void LevelOrder(TreeNode* p)
    {
        queue<TreeNode*> Q;
        Q.push(p); //根节点进队
        TreeNode* t;
        while (!Q.empty())
        {
            t = Q.front(); //t先记住队头,再将队头出队
            Q.pop();
            cout << t->val << " "; //访问队头元素的数据

            if (t->left != NULL)
            {
                Q.push(t->left);
            }

            if (t->right != NULL)
            {
                Q.push(t->right);
            }
        }
        cout << endl;
    }

    //二叉树的销毁
    void Destroy(TreeNode*& subTree)
    {
        if (subTree != NULL)
            {
                Destroy(subTree->left);
                Destroy(subTree->right);
                delete subTree;
                subTree = NULL;
            }
    }


};

class Solution {
public:
    bool check_recursion(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check_recursion(p->left, q->right) && check_recursion(p->right, q->left);
    }

    bool isSymmetric_recursion(TreeNode* root) {
        if (root) {
            TreeNode* root_left, * root_right;
            root_left = root->left;
            root_right = root->right;
            return check_recursion(root_left, root_right);
        }
        else {
            return true;
        }  
    }

    bool check_iteration(TreeNode* u, TreeNode* v) {
        queue<TreeNode*> q;
        q.push(u);
        q.push(v);
        while (!q.empty()) {
            u = q.front();
            q.pop();
            v = q.front();
            q.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric_iteration(TreeNode* root) {
        return check_iteration(root, root);
    }


};


int main()
{
    Tree  T1(0);
    TreeNode* root;
    Solution S1;
    bool flag;
    int list[] = { 1,2,3,0,0,4,0,0,2,4,0,0,3,0,0 };
    cout << "已知的二叉树的前序输入：" << list << endl;
    T1.CreateBinTree_PreOrder(list);
    cout << "该二叉树的层次遍历：" << endl;
    T1.LevelOrder();

    root = T1.getRoot();
    flag = S1.isSymmetric_iteration(root);
    if (flag) {
        cout << "是对称二叉树" << endl;
    }
    else {
        cout << "不是对称二叉树" << endl;
    }

    return 0;
    
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
