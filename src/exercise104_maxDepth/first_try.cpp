/*
给定一个二叉树 root ，返回其最大深度。
二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

示例 1：
    输入：root = [3,9,20,null,null,15,7]
    输出：3

树中节点的数量在 [0, 10^4] 区间内。
-100 <= Node.val <= 100

*/

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left{ nullptr }, right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        /*当前节点的最大深度一定等于子树的最大深度+1*/
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int left_max_depth = maxDepth(root->left);
        int right_max_depth = maxDepth(root->right);

        if (left_max_depth < right_max_depth) {
            left_max_depth = right_max_depth;
        }
        return 1 + left_max_depth;
    }
};


int main()
{

    return 0;
}

/*
* 运行时间8ms, 击败72.04% c++用户
* 消耗内存18.75M, 击败47.73% c++用户
*/
