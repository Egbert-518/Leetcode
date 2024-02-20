/*
给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
差值是一个正数，其数值等于两值之差的绝对值。


示例 1：
    输入：root = [4,2,6,1,3]
    输出：1


树中节点的数目范围是 [2, 10^4]
0 <= Node.val <= 10^5

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
    int getMinimumDifference(TreeNode* root) {
        /*注意是二叉搜索树, 中序遍历是有序的, 所以可以先得到遍历数组, 然后相邻做差的最小值即为返回值*/
        vector<int> nums;
        traversal(root, nums);

        int min_diff = INT32_MAX;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] - nums[i] < min_diff) {
                min_diff = nums[i + 1] - nums[i];
            }
        }

        return min_diff;
    }

    void traversal(TreeNode* root, vector<int>& nums) {
        // 尝试用迭代法做一次
        std::stack<TreeNode*> tree_stack;
        if (root != nullptr) {
            tree_stack.push(root);
        }
        while (!tree_stack.empty())
        {
            TreeNode* node = tree_stack.top();
            tree_stack.pop();
            if (node != nullptr) {
                // 中序遍历是左中右, 但是栈的取出是反向的, 所以按照右中左放入
                if (node->right != nullptr) {
                    tree_stack.push(node->right);
                }

                tree_stack.push(node);
                tree_stack.push(nullptr);

                if (node->left != nullptr) {
                    tree_stack.push(node->left);
                }
            }
            else {
                TreeNode* top = tree_stack.top();
                tree_stack.pop();
                nums.emplace_back(top->val);
            }
        }
    }
};

int main()
{

    return 0;
}

/*
* 运行时间0ms, 击败100.00% c++用户
* 消耗内存23.78M, 击败93.80 c++用户
*/
