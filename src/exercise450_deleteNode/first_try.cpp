/*
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
一般来说，删除节点可分为两个步骤：
首先找到需要删除的节点；
如果找到了，删除它。

示例 1：
    输入：root = [5,3,6,2,4,null,7], key = 3
    输出：[5,4,6,2,null,null,7]
    解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
    一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
    另一个正确答案是 [5,2,6,null,4,null,7]。

示例 2：
    输入: root = [5,3,6,2,4,null,7], key = 0
    输出: [5,3,6,2,4,null,7]
    解释: 二叉树不包含值为 0 的节点

树中的节点数将在 [0, 10^4]的范围内。
-10^5 <= Node.val <= 10^5
节点值唯一
root 是合法的二叉搜索树
-10^5 <= key <= 10^5
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (root->val == key) {
            if (root->left == nullptr && root->right == nullptr) {
                return nullptr;
            }
            else if (root->left == nullptr) {
                return root->right;
            }
            else if (root->right == nullptr) {
                return root->left;
            }
            else {
                insertBST(root->right, root->left);    // 将右插入左然后返回左也是可以的
                return root->right;
            }
        }


        TreeNode* node = root;
        while (node != nullptr)   // 这里是查找值, 所以一定不能是死循环
        {
            // 所有的等于判断都以当前node的左右子树去判断, 防止找不到父节点, root节点已经预先经过了判断, 所以root->val在这里一定不会等于key
            if (key < node->val) {
                if (node->left != nullptr && key == node->left->val) {
                    // 当前节点的左节点要被删除
                    if (node->left->left == nullptr && node->left->right == nullptr) {
                        node->left = nullptr;
                    }
                    else if (node->left->left == nullptr) {
                        node->left = node->left->right;
                    }
                    else if (node->left->right == nullptr) {
                        node->left = node->left->left;
                    }
                    else {
                        insertBST(node->left->left, node->left->right);
                        node->left = node->left->left;
                    }
                    return root;
                }
                else {
                    node = node->left;
                }
            }
            else {
                if (node->right != nullptr && key == node->right->val) {
                    // 当前节点的右节点要被删除
                    if (node->right->left == nullptr && node->right->right == nullptr) {
                        node->right = nullptr;
                    }
                    else if (node->right->left == nullptr) {
                        node->right = node->right->right;
                    }
                    else if (node->right->right == nullptr) {
                        node->right = node->right->left;
                    }
                    else {
                        insertBST(node->right->left, node->right->right);
                        node->right = node->right->left;
                    }
                    return root;
                }
                else {
                    node = node->right;
                }
            }
        }

        return root;
    }

    // 使用这个函数需要保证root至少有一个节点
    void insertBST(TreeNode* root, TreeNode* insert_root) {
        int val = insert_root->val;

        TreeNode* node = root;
        while (true)
        {
            if (val < node->val) {
                if (node->left != nullptr) {
                    node = node->left;
                }
                else {
                    node->left = insert_root;
                    break;
                }
            }
            else {
                if (node->right != nullptr) {
                    node = node->right;
                }
                else {
                    node->right = insert_root;
                    break;
                }
            }
        }
    }
};


int main()
{

    return 0;
}

/*
* 运行时间28ms, 击败69.87% c++用户
* 消耗内存31.45M, 击败95.26% c++用户
*/
