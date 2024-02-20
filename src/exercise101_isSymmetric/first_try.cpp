/*
给你一个二叉树的根节点 root ， 检查它是否轴对称

示例 1：
    输入：root = [1,2,2,3,4,4,3]
    输出：true

树中节点数目在范围 [1, 1000] 内
-100 <= Node.val <= 100

进阶：你可以运用递归和迭代两种方法解决这个问题吗？
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
    TreeNode(int val) : val(val), left{ nullptr }, right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        /*判断这颗树的左树外侧是否与右树外侧相同, 左树内测是否与右树内测相同*/
        return compare(root->left, root->right);
    }

    bool compare(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        else if (left == nullptr && right != nullptr) {
            return false;
        }
        else if (left != nullptr && right == nullptr) {
            return false;
        }
        else {
            // 都非空
            if (left->val != right->val) {
                return false;
            }
            bool outside = compare(left->left, right->right);
            bool inside = compare(left->right, right->left);
            return (outside && inside);
        }
    }
};


int main()
{
    TreeNode* left21 = new TreeNode(3);
    TreeNode* right21 = new TreeNode(4);
    TreeNode* left22 = new TreeNode(4);
    TreeNode* right22 = new TreeNode(3);

    TreeNode* left11 = new TreeNode(2, left21, right21);
    TreeNode* right11 = new TreeNode(2, left22, right22);

    TreeNode* root = new TreeNode(1, left11, right11);

    Solution solution;
    solution.isSymmetric(root);

    return 0;
}

/*
* 运行时间12ms, 击败8.05% c++用户
* 消耗内存16.30M, 击败84.08% c++用户
*/
