/*
二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。

示例1:
    输入：root = [1,2,3]
    输出：6
    解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6

示例 2：
    输入：root = [-10,9,20,null,null,15,7]
    输出：42
    解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42


树中节点数目范围是 [1, 3 * 10^4]
-1000 <= Node.val <= 1000
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        /*后序遍历(左右中), 对中节点判断左右节点, 取左右节点值大于0且最大的那个与自身值相加, 一直往上, 过程中记录最大中节点的值*/
        backtracking(root);
        return max_sum;
    }

    void backtracking(TreeNode* node) {
        if (node->left != nullptr) {
            backtracking(node->left);   // 左
        }
        if (node->right != nullptr) {
            backtracking(node->right);  // 右
        }
        // 中节点, 看左右节点的值
        int left_val = node->left == nullptr ? 0 : node->left->val;
        int right_val = node->right == nullptr ? 0 : node->right->val;
        if (node->val + left_val + right_val > max_sum) {
            max_sum = node->val + left_val + right_val;   // 到此中断, 也就是取左中右为和, 不过递归还可以向上蔓延
        }

        if (left_val > right_val && left_val > 0) {
            node->val = node->val + left_val;
        }
        else if (right_val > left_val && right_val > 0) {
            node->val = node->val + right_val;
        }
        if (node->val > max_sum) {
            max_sum = node->val;
        }
    }

private:
    int max_sum = INT32_MIN;
};


int main()
{
    Solution solution;

    return 0;
}

/*
* 运行时间19ms, 击败73.81% c++用户
* 消耗内存25.57M, 击败66.45% c++用户
*/
