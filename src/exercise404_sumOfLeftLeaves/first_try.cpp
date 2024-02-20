/*
给定二叉树的根节点 root ，返回所有左叶子之和。

示例 1：
    输入: root = [3,9,20,null,null,15,7]
    输出: 24
    解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

示例 2：
    输入: root = [1]
    输出: 0

节点数在 [1, 1000] 范围内
-1000 <= Node.val <= 1000

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
    int sumOfLeftLeaves(TreeNode* root) {
        /*只有左叶子才会进行加和, 否则不算(即不是左节点都加和)*/
        int sum = 0;
        traversal(root, sum);
        return sum;
    }

    void traversal(TreeNode* node, int& sum) {
        if (node->left == nullptr && node->right == nullptr) {
            return;
        }

        if (node->left != nullptr) {
            if (node->left->left == nullptr && node->left->right == nullptr) {
                sum = sum + node->left->val;
            }
            traversal(node->left, sum);
        }
        if (node->right != nullptr) {
            traversal(node->right, sum);
        }
    }
};


int main()
{

    return 0;
}

/*
* 运行时间5ms, 击败19.50% c++用户
* 消耗内存14.42M, 击败5.19% c++用户
*/
