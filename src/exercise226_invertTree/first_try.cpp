/*
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

示例 1：
    输入：root = [4,2,7,1,3,6,9]
    输出：[4,7,2,9,6,3,1]

树中节点数目范围在 [0, 100] 内
-100 <= Node.val <= 100
*/

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        /*思路是, 前序遍历树, 交换节点的左右孩子指向*/
        if (root == nullptr) {
            return root;   // 停止条件, 返回
        }
        TreeNode* left = root->left;
        root->left = root->right;
        root->right = left;     // 先交换当前节点的左右孩子节点
        root->left = invertTree(root->left);      // 递归方式使左孩子节点的左右孩子进行交换
        root->right = invertTree(root->right);

        return root;
    }
};


int main()
{

    return 0;
}

/*
* 运行时间0ms, 击败100.00% c++用户
* 消耗内存9.74M, 击败81.22% c++用户
*/
