/*
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
假设二叉树中至少有一个节点。

示例 1：
    输入: root = [2,1,3]
    输出: 1

示例 2：
    输入: [1,2,3,4,null,5,6,null,null,7]
    输出: 7

二叉树的节点个数的范围是 [1,10^4]
-231 <= Node.val <= 231 - 1

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
    int findBottomLeftValue(TreeNode* root) {
        /*最底层最左边, 用层序遍历是否比较简单, 广度优先, 用deque*/
        std::deque<TreeNode*> queue;
        queue.push_back(root);

        int bottom_left_val = root->val;
        while (!queue.empty())
        {
            int size = queue.size();
            // 处理这层最左边的节点
            bottom_left_val = queue.front()->val;   // 因为非空, front一定有意义, 因此更新这个值
            for (int i = 0; i < size; i++)
            {
                TreeNode* cur_node = queue.front();
                queue.pop_front();
                if (cur_node->left != nullptr) {
                    queue.push_back(cur_node->left);
                }
                if (cur_node->right != nullptr) {
                    queue.push_back(cur_node->right);
                }
            }
        }

        return bottom_left_val;

    }
};


int main()
{

    return 0;
}

/*
* 运行时间12ms, 击败63.53% c++用户
* 消耗内存19.79M, 击败99.06% c++用户
*/
