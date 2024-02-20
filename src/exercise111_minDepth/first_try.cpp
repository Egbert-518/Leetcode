/*
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明：叶子节点是指没有子节点的节点。

示例 1：
    输入：root = [3,9,20,null,null,15,7]
    输出：2

示例 1：
    输入：root = [2,null,3,null,4,null,5,null,6]
    输出：5

树中节点数的范围在 [0, 10^5] 内
-1000 <= Node.val <= 1000

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
    int minDepth(TreeNode* root) {
        /*遍历二叉树, 当指向左节点或右节点时, 深度值加一, 当到叶子节点时, 更新最小深度值, 当回溯到中间节点时, 深度值减一*/
        if (root == nullptr) {
            return 0;
        }
        int min_depth = INT32_MAX;
        traversal(root, min_depth, 1);
        return min_depth;
    }

    void traversal(TreeNode* node, int& min_depth, int cur_depth) {
        if (node->left == nullptr && node->right == nullptr) {
            // 到叶子节点了
            if (min_depth > cur_depth) {
                min_depth = cur_depth;
            }
            return;
        }
        if (node->left != nullptr) {
            traversal(node->left, min_depth, cur_depth + 1);
        }
        if (node->right != nullptr) {
            traversal(node->right, min_depth, cur_depth + 1);
        }
    }
};


int main()
{

    return 0;
}

/*
* 运行时间252ms, 击败30.69% c++用户
* 消耗内存143.48M, 击败53.00% c++用户
*/
