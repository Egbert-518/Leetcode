/*
给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
    一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

示例 1：
    输入：root = [3,9,20,null,null,15,7]
    输出：true

示例 3：
    输入：root = []
    输出：true

树中的节点数在范围 [0, 5000] 内
-10^4 <= Node.val <= 10^4

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
    bool isBalanced(TreeNode* root) {
        /*在这里增加一个leetcode中二叉树的知识点, 我们之前知道每个节点的深度是从根节点到这个节点经过最长的简单边的数量(需+1, 因为根节点本身深度为1),
          现补充节点的高度知识, 高度则为从该节点到叶子节点的最长简单边数量(同样需+1, 认为叶子节点的高度为1)*/
          /*因此不断递归左右子树, 当子树非平衡子树时, 一定不是平衡二叉树*/
        return getHeight(root) == -1 ? false : true;
    }
    int getHeight(TreeNode* node) {
        // 返回以node为根节点的树的最大高度
        if (node == nullptr) {
            return 0;    // 叶子节点的高度必为1
        }
        int left_result = getHeight(node->left);
        if (left_result == -1) {
            return -1;
        }
        int right_result = getHeight(node->right);
        if (right_result == -1) {
            return -1;
        }
        if (abs(left_result - right_result) > 1) {
            return -1;
        }
        else {
            return 1 + max(left_result, right_result);    // 只要子树是满足平衡二叉树的, 就应该把高度值记录返回给上一级的节点比较左右最大高度差
        }
    }
};


int main()
{

    return 0;
}

/*
* 运行时间12ms, 击败63.21% c++用户
* 消耗内存21.05M, 击败11.58% c++用户
*/
