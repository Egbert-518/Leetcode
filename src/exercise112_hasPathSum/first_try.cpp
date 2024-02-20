/*
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。

示例 1：
    输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
    输出：true

示例 2：
    输入：root = [1,2,3], targetSum = 5
    输出：false
    解释：树中存在两条根节点到叶子节点的路径：
    (1 --> 2): 和为 3
    (1 --> 3): 和为 4
    不存在 sum = 5 的根节点到叶子节点的路径。

示例 3：
    输入：root = [], targetSum = 0
    输出：false
    解释：由于树是空的，所以不存在根节点到叶子节点的路径。

树中节点的数目在范围 [0, 5000] 内
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000

*/

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <string>
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        /*递归? 从根节点开始, 减去根节点的值, 在传递给左右子树, 直到叶子节点, 注意必须是到叶子节点才行, 到中途一个节点和为该值也不应该直接返回true*/
        if (root == nullptr) {
            return false;
        }
        return traversal(root, targetSum);
    }

    bool traversal(TreeNode* node, int cur_target) {
        if (node->left == nullptr && node->right == nullptr) {
            // 到叶子节点
            if (node->val == cur_target) {
                return true;
            }
            else {
                return false;
            }
        }
        bool left_result = false, right_result = false;
        if (node->left != nullptr) {
            left_result = traversal(node->left, cur_target - node->val);
        }
        if (node->right != nullptr) {
            right_result = traversal(node->right, cur_target - node->val);
        }

        return (left_result || right_result);
    }
};


int main()
{

    return 0;
}

/*
* 运行时间14ms, 击败17.60% c++用户
* 消耗内存19.36M, 击败98.94% c++用户
*/
