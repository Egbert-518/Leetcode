/*
给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

提醒一下，二叉搜索树满足下列约束条件：
    节点的左子树仅包含键 小于 节点键的节点。
    节点的右子树仅包含键 大于 节点键的节点。
    左右子树也必须是二叉搜索树。

示例 1：
    输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
    输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

示例 2：
    输入：root = [0,null,1]
    输出：[1,null,1]

树中的节点数介于 0 和 10^4 之间。
每个节点的值介于 -10^4 和 10^4 之间。
树中的所有值 互不相同 。
给定的树为二叉搜索树。
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
    TreeNode* convertBST(TreeNode* root) {
        /*如果有右中左的遍历方式, 只需要遍历一遍即可, 因为是从最大的往小遍历, 那么之前节点值与当前节点的值累加即替换当前节点值, 且这个累加值一次遍历即可*/
        /*考虑迭代法中将左右顺序调换即可*/
        if (root == nullptr) {
            return root;
        }
        std::stack<TreeNode*> tree_stack;
        tree_stack.push(root);
        int cur_sum = 0;

        while (!tree_stack.empty())
        {
            TreeNode* node = tree_stack.top();
            tree_stack.pop();
            if (node != nullptr) {
                // 最终想要右中左, 则按左中右顺序入栈
                if (node->left != nullptr) {
                    tree_stack.push(node->left);
                }

                tree_stack.push(node);
                tree_stack.push(nullptr);

                if (node->right != nullptr) {
                    tree_stack.push(node->right);
                }
            }
            else {
                TreeNode* top = tree_stack.top();
                tree_stack.pop();
                cur_sum = cur_sum + top->val;
                top->val = cur_sum;
            }
        }

        return root;
    }
};


int main()
{

    return 0;
}

/*
* 运行时间37ms, 击败19.92% c++用户
* 消耗内存32.67M, 击败92.64% c++用户
*/
